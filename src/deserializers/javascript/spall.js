const HEADER_SIZE = 32;
const EVENT_BEGIN_SIZE = 20;
const EVENT_END_SIZE = 17;

class SpallProfiler {
    constructor(outputPath) {
        this.outputPath = outputPath;
        this.events = [];
    }

    serialize() {
        const eventBegins = this.events.filter(event => event.type === 3);
        const eventEnds = this.events.filter(event => event.type === 4);

        const ends = eventEnds.length * EVENT_END_SIZE
        const starts = eventBegins.length * EVENT_BEGIN_SIZE + eventBegins.reduce((acc, begin) => acc + begin.name.length, 0);
        const size = HEADER_SIZE + starts + ends;
        const buffer = new ArrayBuffer(size);
        const view = new DataView(buffer);

        let offset = 0;
        view.setBigUint64(offset, 0x0BADF00Dn, true); // magic
        offset += 8;
        view.setBigUint64(offset, 1n, true); // version
        offset += 8;
        view.setFloat64(offset, 1.0e-3, true); // timestamp_unit
        offset += 8;
        view.setBigUint64(offset, 0n, true); // must_be_0
        offset += 8;

        if(eventBegins.length !== eventEnds.length) {
            throw new Error("Mismatched begin and end events");
        }

        for(const e of this.events) {
            if(e.type === 3) {
                view.setUint8(offset, e.type);
                offset += 1;
                view.setUint8(offset, e.category);
                offset += 1;
                view.setUint32(offset, e.pid, true);
                offset += 4;
                view.setUint32(offset, e.tid, true);
                offset += 4;
                view.setFloat64(offset, e.time, true);
                offset += 8;
                view.setUint8(offset, e.name.length);
                offset += 1;
                view.setUint8(offset, e.args_len);
                offset += 1;

                const nameAsBytes = new TextEncoder().encode(e.name);
                for(let j = 0; j < nameAsBytes.length; j++) {
                    view.setUint8(offset, nameAsBytes[j]);
                    offset += 1;
                }
            } else if(e.type === 4) {
                view.setUint8(offset, e.type);
                offset += 1;
                view.setUint32(offset, e.pid, true);
                offset += 4;
                view.setUint32(offset, e.tid, true);
                offset += 4;
                view.setFloat64(offset, e.time, true);
                offset += 8;
            } else {
                throw new Error("Unknown event type");
            }
        }

        return view;
    }

    trace_begin(functionName) {
        if(typeof process === 'object') {
            const hrTime = global.process.hrtime();
            this.events.push({
                             type: 3, // begin
                             category: 0,
                             pid: 1,
                             tid: 1,
                             time: hrTime[0] * 1000000000 + hrTime[1],
                             name: functionName,
                             args_len: 0,
            });
        }
    }

    trace_end() {
        if(typeof process === 'object') {
            const hrTime = global.process.hrtime();
            this.events.push({
                             type: 4, // end
                             pid: 1,
                             tid: 1,
                             time: hrTime[0] * 1000000000 + hrTime[1],
            });
        }
    }
}

module.exports = SpallProfiler;

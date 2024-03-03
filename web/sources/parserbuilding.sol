pragma solidity 0.4.4;
pragma solidity ^0.4.4;
pragma solidity ~0.4.4;
pragma solidity >0.4.4;
pragma solidity >=0.4.4;
pragma solidity <0.4.4;
pragma solidity <=0.4.4;
pragma solidity =0.4.4;
pragma solidity 0.4;
pragma solidity >=0.5.0 <0.7.0;
pragma solidity ^0.6;
pragma solidity ^0.5.0 || ^0.6.0;
pragma solidity ^0.5.0 || ^0.6.0 || ^0.7.0;
pragma solidity *;
pragma experimental ABIEncoderV2;

import "./abc.sol";
import "./def.sol";
import './abc.sol';
import './def.sol';
import "./abc.sol" as x;
import './abc.sol' as my_abc;
import * as y from "./abc.sol";
import * as abc from './abc.sol';
import {a as b, c as d, f} from "./abc.sol";
import { a as my_a, b as my_b } from './abc.sol';

enum Locations {
    Continent,
    Empire,
    Union,
    Country,
    State,
    City,
    Council,
    Village
}

struct KeyValuePair {
    address a0;
    bool a1;
    string a2;
    bytes a3;
    int a4;
    int8 a5;
    int16 a6;
    int24 a7;
    int32 a8;
    int40 a9;
    int48 a10;
    int56 a11;
    int64 a12;
    int72 a13;
    int80 a14;
    int88 a15;
    int96 a16;
    int104 a17;
    int112 a18;
    int120 a19;
    int128 a20;
    int136 a21;
    int144 a22;
    int152 a23;
    int160 a24;
    int168 a25;
    int176 a26;
    int184 a27;
    int192 a28;
    int200 a29;
    int208 a30;
    int216 a31;
    int224 a32;
    int232 a33;
    int240 a34;
    int248 a35;
    int256 a36;
    uint a37;
    uint8 a38;
    uint16 a39;
    uint24 a40;
    uint32 a41;
    uint40 a42;
    uint48 a43;
    uint56 a44;
    uint64 a45;
    uint72 a46;
    uint80 a47;
    uint88 a48;
    uint96 a49;
    uint104 a50;
    uint112 a51;
    uint120 a52;
    uint128 a53;
    uint136 a54;
    uint144 a55;
    uint152 a56;
    uint160 a57;
    uint168 a58;
    uint176 a59;
    uint184 a60;
    uint192 a61;
    uint200 a62;
    uint208 a63;
    uint216 a64;
    uint224 a65;
    uint232 a66;
    uint240 a67;
    uint248 a68;
    uint256 a69;
    bytes1 a70;
    bytes2 a71;
    bytes3 a72;
    bytes4 a73;
    bytes5 a74;
    bytes6 a75;
    bytes7 a76;
    bytes8 a77;
    bytes9 a78;
    bytes10 a79;
    bytes11 a80;
    bytes12 a81;
    bytes13 a82;
    bytes14 a83;
    bytes15 a84;
    bytes16 a85;
    bytes17 a86;
    bytes18 a87;
    bytes19 a88;
    bytes20 a89;
    bytes21 a90;
    bytes22 a91;
    bytes23 a92;
    bytes24 a93;
    bytes25 a94;
    bytes26 a95;
    bytes27 a96;
    bytes28 a97;
    bytes29 a98;
    bytes30 a99;
    bytes31 a100;
    bytes32 a101;
    fixed a102;
    ufixed a103;

    abc.a a102;
    abc.b a103;
    MyContract.MyStruct a104;
    MyContract.MyStruct1.MyStruct2 a105;
    mapping(address => uint) a106;
    mapping(address => mapping(address => uint)) a107;

    mapping(uint=>x) a108;
    mapping(address => bytes32) a109;
    mapping(bytes32 => test_struct) a110;
    mapping (uint64 => mapping (bytes32 => uint)) a111;
    mapping (address a => bool b) a112;
    mapping(address=>bytes32) a113;
    mapping(address=>bytes32) a114;
    mapping (Foo => uint) a115;
    mapping (address => bool) a116;
    mapping (address a => bool) a117;
    mapping (address => bool b) a118;

    uint[] a119;
    uint[][] a120;
    uint[][][] a121;
    KeyValuePair[] a122;
    Locations a123;
    mapping(uint=>x)[] a124;
}

error TopLevelCustomError();
error TopLevelCustomErrorWithArg(uint x);
error TopLevelCustomErrorArgWithoutName(string);

event e1();
event e2(uint[] a, bytes7[] indexed b, c[] x);
event e3() anonymous;
event e4(uint a, bytes32 s);
event e5(uint a, bytes32 indexed s, bool indexed b);


event AavePoolUpdated(address updated, address caller);
event AavePortalFeeUpdated(uint256 updated, address caller);
event AavePortalMintUnbacked(bytes32 indexed transferId, address indexed router, address asset, uint256 amount);
event AavePortalRepayment(bytes32 indexed transferId, address asset, uint256 amount, uint256 fee, address caller);
event AcceptAdminRole(address newAdmin);
event AccountBlacklisted(address indexed account);
event AccountWhitelisted(address indexed account);
event ActivateForceBatches();
event AddInboundProofLibraryForChain(uint16 indexed chainId, address lib);
event AddedOwner(address owner);
event AddedSharedMember(uint256 indexed roleId, address indexed newMember, address indexed manager);
event AddedToWhitelist(address indexed addedAddress);
event AddressImported(bytes32 name, address destination);
event AddressSet(string indexed _name, address _newAddress, address _oldAddress);
event AddressSet(string indexed name, address newAddress, address oldAddress);
event AdminChanged(address previousAdmin, address newAdmin);
event AdminFeesSet(bytes32 indexed key, uint256 newAdminFee, address caller);
event AdminFeesWithdrawn(bytes32 indexed key, address caller);
event AdminPropertiesSet(IERC20 defaultCurrency, uint64 defaultLiveness, uint256 burnedBondPercentage);
event AggregateRootPropagated(bytes32 indexed aggregateRoot, bytes32 domainsHash);
event AggregateRootReceived(bytes32 indexed root);
event AggregateRootRemoved(bytes32 indexed root);
event AggregateRootSavedOptimistic(bytes32 indexed aggregateRoot, uint256 rootTimestamp);
event AggregateRootVerified(bytes32 indexed root);
event AllTokensFrozen();
event AllTokensUnfrozen();
event AllowListAddressSet(address indexed user, bool val);
event AllowListEnabledUpdated(bool isEnabled);
event AllowedExecutorDestinationsUpdated(address indexed destination, bool isSet);
event AppConfigUpdated(address indexed userApplication, uint indexed configType, bytes newConfig);
event Approval(address indexed owner, address indexed approved, uint256 indexed tokenId);
event Approval(address indexed owner, address indexed spender, uint value);
event Approval(address indexed owner, address indexed spender, uint256 amount);
event Approval(address indexed owner, address indexed spender, uint256 value);
event Approval(address indexed src, address indexed guy, uint256 wad);
event ApprovalForAll(address indexed account, address indexed operator, bool approved);
event ApprovalForAll(address indexed owner, address indexed operator, bool approved);
event Approve(address indexed token, address indexed spender, uint256 value);
event ApproveCutUpgradeNoticePeriod(address indexed addr);
event ApproveHash(bytes32 indexed approvedHash, address indexed owner);
event ArboristUpdated(address previous, address updated);
event AssertionDisputed(bytes32 indexed assertionId, address indexed caller, address indexed disputer);
event AssetRebalanced();
event AssetRemoved(bytes32 indexed key, address caller);
event AssignRoleAdmin(address admin);
event AssignRoleRouter(address router);
event AssignRoleWatcher(address watcher);
event AuthorizedOperator(address indexed operator, address indexed tokenHolder);
event AvatarSet(address indexed previousAvatar, address indexed newAvatar);
event BatchRefundERC1155(address indexed token, address indexed recipient, uint256[] tokenIds, uint256[] amounts);
event BatchRefundERC721(address indexed token, address indexed recipient, uint256[] tokenIds);
event BeaconUpgraded(address indexed beacon);
event BeneficiaryUpdated(address newBeneficiary);
event BlockCommit(uint256 indexed batchNumber, bytes32 indexed batchHash, bytes32 indexed commitment);
event BlockCommit(uint32 indexed blockNumber);
event BlockExecution(uint256 indexed batchNumber, bytes32 indexed batchHash, bytes32 indexed commitment);
event BlockVerification(uint32 indexed blockNumber);
event BlocksRevert(uint256 totalBatchesCommitted, uint256 totalBatchesVerified, uint256 totalBatchesExecuted);
event BlocksRevert(uint32 totalBlocksVerified, uint32 totalBlocksCommitted);
event BlocksVerification(uint256 indexed previousLastVerifiedBatch, uint256 indexed currentLastVerifiedBatch);
event BondSet(uint256 bond);
event BridgeApproval(address _token, address indexed spender, uint value);
event BridgeCallTriggered(address indexed outbox, address indexed to, uint256 value, bytes data);
event BridgeOperatorsAdded(bool[] statuses, uint96[] voteWeights, address[] governors, address[] bridgeOperators);
event BridgeOperatorsRemoved(bool[] statuses, address[] bridgeOperators);
event BridgeTokens(address destinationAddress, uint256 amount);
event BridgedToken(uint64 nonce);
event Burn(address indexed account, uint256 amount);
event Burn(address indexed account, uint256 tokenId);
event Burn(address indexed sender, uint amount0, uint amount1, address indexed to);
event Burned(address indexed operator, address indexed from, uint256 amount, bytes data, bytes operatorData);
event CacheUpdated(bytes32 name, address destination);
event CallExecuted(bytes32 indexed id, uint256 indexed index, address target, uint256 value, bytes data);
event CallSalt(bytes32 indexed id, bytes32 salt);
event CancelTransaction(bytes32 indexed txHash, address indexed target, uint value, string signature,  bytes data, uint eta);
event Canceled(bytes32 indexed ticketId);
event Cancelled(bytes32 indexed id);
event CapacitorFactorySet(address capacitorFactory);
event CastVote(uint256 indexed voteId, address indexed voter, bool supports, uint256 stake);
event ChallengeEnded(uint64 indexed challengeIndex, ChallengeTerminationType kind);
event ChangeBufferBlocks(uint64 bufferBlocks);
event ChangeExecutionDelayBlocks(uint64 executionDelayBlocks);
event ChangeMinDelay(uint256 _delayBefore, uint256 _delayAfter);
event ChangeMinOpenVoteAmount(uint256 minOpenVoteAmount);
event ChangeMinQuorum(uint64 minAcceptQuorumPct);
event ChangePermissionManager(address indexed app, bytes32 indexed role, address indexed manager);
event ChangeSecurityCouncil(address _securityCouncilBefore, address _securityCouncilAfter);
event ChangeSupportRequired(uint64 supportRequiredPct);
event ChangedFallbackHandler(address handler);
event ChangedGuard(address guard);
event ChangedThreshold(uint256 threshold);
event ClaimTokens(address destinationAddress, uint256 amount);
event ClaimedFailedDeposit(address indexed to, address indexed l1Token, uint256 amount);
event ClaimedTokens(address indexed _token, address indexed _controller, uint _amount);
event Closed();
event CommitBatch(uint256 indexed batchIndex, bytes32 indexed batchHash);
event CommitmentUpdated(uint32 domain, bytes32 commitment);
event ConfigUpdate(UpdateType indexed updateType, bytes data);
event ConfigUpdate(uint256 indexed version, UpdateType indexed updateType, bytes data);
event ConnectorAdded(uint32 domain, address connector, uint32[] domains, address[] connectors);
event ConnectorPlugDisconnected();
event ConnectorPoolIdUpdated(address connector, uint256 poolId);
event ConnectorRemoved(uint32 domain, address connector, uint32[] domains, address[] connectors, address caller);
event ContractCallExecuted(bytes32 indexed commandId);
event ContractExpired(address indexed caller);
event ContractMapUpdated(bytes32 indexed key, address indexed previousContract, address indexed newContract);
event ContractUpdated(ContractType indexed contractType, address indexed addr);
event ConvertedToEsXai(address indexed user, uint256 amount);
event CounterEvent(uint64 count);
event CreatedConfigStore(address indexed configStoreAddress, address indexed ownerAddress);
event CreatedExpiringMultiParty(address indexed expiringMultiPartyAddress, address indexed deployerAddress);
event CreatedPerpetual(address indexed perpetualAddress, address indexed deployerAddress);
event CurrentMonthWithdrawnAmountReset(uint256);
event CurrentYearWithdrawnAmountReset(uint256);
event DAIBridged(address indexed bridgoor, uint256 amount, uint256 total);
event DAIClaimed(address indexed bridgoor, uint256 amount, uint256 total);
event DAOFunded(uint amountDAO, uint amountBurn);
event DailyWithdrawalLimitsUpdated(address[] tokens, uint256[] limits);
event DefaultAdminDelayChangeCanceled();
event DefaultAdminDelayChangeScheduled(uint48 newDelay, uint48 effectSchedule);
event DefaultAdminTransferCanceled();
event DefaultAdminTransferScheduled(address indexed newAdmin, uint48 acceptSchedule);
event DefaultGatewayUpdated(address newDefaultGateway);
event DefaultIsmSet(address indexed module);
event DefaultReceiveVersionSet(uint16 version);
event DefaultSendVersionSet(uint16 version);
event DelayBlocksUpdated(uint256 indexed updated, address caller);
event DelayBlocksUpdated(uint256 previous, uint256 updated);
event DelegatedPowerChanged(address indexed user, uint256 amount, DelegationType delegationType);
event DeleteWindow(uint256 indexed windowIndex, address owner);
event Deny(address indexed usr);
event DeployDAO(address dao);
event DeployEVMScriptRegistry(address reg);
event Deposit(address indexed dst, uint256 wad);
event Deposit(address indexed sponsor, uint256 indexed collateralAmount);
event Deposit(address indexed user, uint256 indexed collateralAmount);
event Deposit(uint16 indexed tokenId, uint128 amount);
event DepositETH(address indexed from, address indexed to, uint256 amount, bytes data);
event DepositEtherPaused(bool new_status);
event DepositMessageDelivered(address indexed sender);
event DepositRequested(bytes32 receiptHash, Transfer.Receipt receipt);
event DepositSent(bytes indexed pubKey, bytes withdrawalCredential);
event DepositsDisabled(address indexed disabler);
event DepositsEnabled(address indexed enabler);
event DequeueTransaction(uint256 startIndex, uint256 count, uint256 skippedBitmap);
event DiamondCut(FacetCut[] _diamondCut, address _init, bytes _calldata);
event DiamondCut(FacetCut[] facetCuts, address initAddress, bytes initCalldata);
event DiamondCut(IDiamondCut.FacetCut[] _diamondCut, address _init, bytes _calldata);
event DiamondCutProposed(FacetCut[] _diamondCut, address _init, bytes _calldata, uint256 deadline);
event DiamondCutProposed(IDiamondCut.FacetCut[] _diamondCut, address _init, bytes _calldata, uint256 deadline);
event DiamondCutRescinded(FacetCut[] _diamondCut, address _init, bytes _calldata);
event DiamondCutRescinded(IDiamondCut.FacetCut[] _diamondCut, address _init, bytes _calldata);
event DisableExecutor(uint256 indexed executorId, address indexed executorAddress);
event DisabledModule(address module);
event Dispatch(bytes32 indexed leaf, uint256 indexed index, bytes32 indexed root, bytes message);
event DispatchId(bytes32 indexed messageId);
event DisputeBlocksUpdated(uint256 previous, uint256 updated);
event DomainAdded(uint32 domain, address connector);
event DomainAdded(uint32 indexed hyperlaneDomain, uint32 circleDomain);
event DomainRemoved(uint32 domain);
event DropTransaction(uint256 index);
event EIP712DomainChanged();
event ETHBridgeFinalized(address indexed from, address indexed to, uint256 amount, bytes extraData);
event ETHBridgeInitiated(address indexed from, address indexed to, uint256 amount, bytes extraData);
event ETHDepositInitiated(address indexed from, address indexed to, uint256 amount, bytes extraData);
event ETHSubmitted(address indexed sender, address indexed recipient, uint256 sent_amount, uint256 withheld_amt);
event ETHWithdrawalFinalized(address indexed from, address indexed to, uint256 amount, bytes extraData);
event EmergencyDeleteRootBundle(uint256 indexed rootBundleId);
event EmergencyERC20Recovered(address tokenAddress, uint256 tokenAmount);
event EmergencyEtherRecovered(uint256 amount);
event EmergencyExecution(address indexed to, uint256 value, bytes data);
event EmergencyPaused(address account);
event EmergencyShutdown(address indexed caller, uint256 originalExpirationTimestamp, uint256 shutdownTimestamp);
event EmergencyShutdown(address indexed caller, uint256 shutdownTimestamp);
event EmergencyStateActivated();
event EmergencyStateDeactivated();
event EmergencyUnpaused(address account);
event EnableEmergencyWithdraw(bool enabled, uint unlockTime);
event EnableExecutor(uint256 indexed executorId, address indexed executorAddress);
event EnableSupportedOutboundProof(uint16 indexed chainId, uint16 proofType);
event EnabledDepositRoute(address indexed originToken, uint256 indexed destinationChainId, bool enabled);
event EnabledModule(address module);
event EndedDepositBox(address indexed user);
event EndedSponsorPosition();
event EndedSponsorPosition(address indexed sponsor);
event EsXaiAddressSet(address indexed newEsXaiAddress);
event EthWithdrawalFinalized(address indexed to, uint256 amount);
event ExcessStateTransferFeePercChanged(address indexed tokenAddress, uint256 indexed fee);
event ExchangeRateUpdated(address exchangeRate);
event ExecuteTransaction(bytes32 indexed txHash, address indexed target, uint value, string signature,  bytes data, uint eta);
event ExecuteUpgrade(Diamond.DiamondCutData diamondCut);
event ExecuteVote(uint256 indexed voteId);
event Executed(bytes32 indexed commandId);
event Executed(uint x);
event ExecutionChallengeBegun(uint64 indexed challengeIndex, uint256 blockSteps);
event ExecutionFailure(bytes32 txHash, uint256 payment);
event ExecutionFeesSet(uint256 siblingChainSlug, uint128 executionFees);
event ExecutionFromModuleFailure(address indexed module);
event ExecutionFromModuleSuccess(address indexed module);
event ExecutionManagerSet(address executionManager);
event ExecutionSuccess(bytes32 msgId);
event ExecutionSuccess(bytes32 txHash, uint256 payment);
event ExecutorAdded(address executor, address owner);
event ExecutorAuthorized(address executor);
event ExecutorRemoved(address executor, address owner);
event ExecutorSet(address executor);
event ExecutorUnauthorized(address executor);
event ExecutorUpdated(address indexed executor, bool isExecutor);
event ExodusMode();
event ExternalCalldataExecuted(bytes32 indexed transferId, bool success, bytes returnData);
event FactAuth(address indexed sender, uint32 nonce, bytes fact);
event FailedLog(string reason);
event FailedLogBytes(bytes reason);
event FailedRelayedMessage(bytes32 indexed messageHash);
event FailedRelayedMessage(bytes32 indexed msgHash);
event FailedRelayedMessage(bytes32 msgHash);
event FeeChanged(address indexed tokenAddress, uint256 indexed equilibriumFee, uint256 indexed maxFee);
event FeeEnabled(bool feeEnabled);
event FinalFeesPaid(uint256 indexed amount);
event FinalizeBatch(uint256 indexed batchIndex, bytes32 indexed batchHash, bytes32 stateRoot, bytes32 withdrawRoot);
event FinalizeDepositETH(address indexed from, address indexed to, uint256 amount, bytes data);
event FinalizeWithdrawETH(address indexed from, address indexed to, uint256 amount, bytes data);
event Finalized();
event FinalizedImplementation(address indexed implementation);
event ForceReceiveLocal(bytes32 indexed transferId);
event Freeze();
event Frozen(address indexed owner);
event FundingRateUpdated(int256 newFundingRate, uint256 indexed updateTime, uint256 reward);
event FundsWithdrawn(address indexed to, uint256 amount);
event FxChildTunnelSet(address fxChildTunnel, address newFxChildTunnel);
event FxChildUpdate(address oldFxChild, address newFxChild);
event FxRootTunnelSet(address fxRootTunnel, address newFxRootTunnel);
event GasCapUpdated(uint256 _previous, uint256 _updated);
event GasFloorUpdated(uint256 previous, uint256 updated);
event GasPriceCapUpdated(uint256 _previous, uint256 _updated);
event GatewaySet(address indexed l1Token, address indexed gateway);
event GlobalTripChanged(bool isGlobalTipped);
event GovernanceStrategyChanged(address indexed newStrategy, address indexed initiatorChange);
event GovernanceTransferred(address indexed previousGovernance, address indexed newGovernance);
event GrantAccess(bytes32 indexed role, address indexed target, bytes4[] selectors);
event Handled(bytes32 blockHash);
event HashReceived(uint16 indexed srcChainId, address indexed oracle, bytes32 lookupHash, bytes32 blockData, uint confirmations);
event HasherSet(address hasher);
event HighTierThresholdsUpdated(address[] tokens, uint256[] thresholds);
event HubDomainCleared();
event HubDomainSet(uint32 domain);
event ImplementationAdded(address indexed implementation, bytes initializer, bool finalize);
event ImplementationRemoved(address indexed implementation);
event ImplementationRemoved(address indexed implementation, bytes initializer, bool finalize);
event ImplementationUpgraded(address indexed implementation, bytes initializer);
event InboxMessageDelivered(uint256 indexed messageNum, bytes data);
event InboxMessageDeliveredFromOrigin(uint256 indexed messageNum);
event InboxToggle(address indexed inbox, bool enabled);
event InflationRateCapLowered(uint256, uint256);
event InflationRecipientDewhitelisted(address);
event InflationRecipientWhitelisted(address);
event InflationRecipientsWhitelistingDisabled();
event InitializeOverload();
event Initialized(address indexed admin);
event Initialized(uint8 version);
event InitiatedNativeConfirmation(bytes32 packetId);
event InterchainGasPaymasterSet(address indexed interchainGasPaymaster);
event InterchainSecurityModuleSet(address indexed module);
event InterfaceImplementationChanged(bytes32 indexed interfaceName, address indexed newImplementationAddress);
event InterfaceImplementerSet(address indexed account, bytes32 indexed interfaceHash, address indexed implementer);
event IntrinsicParamsUpdated(uint256 txGas, uint256 txGasContractCreation, uint256 zeroGas, uint256 nonZeroGas);
event InvalidDst(uint16 indexed srcChainId, bytes srcAddress, address indexed dstAddress, uint64 nonce, bytes32 payloadHash);
event InvalidateKeyset(bytes32 indexed keysetHash);
event IsPorterAvailableStatusUpdate(bool isPorterAvailable);
event IsSequencerUpdated(address addr, bool isSequencer);
event KeysCleared();
event L2BaseFeeUpdated(uint256 oldL2BaseFee, uint256 newL2BaseFee);
event LPTokenTargetUpdated(address oldAddress, address newAddress, address caller);
event LRCClaimed(uint amount);
event LRCRewarded     (address indexed user,  uint amount);
event LRCStaked       (address indexed user,  uint amount);
event LRCWithdrawn    (address indexed user,  uint amount);
event LeafInserted(bytes32 root, uint256 count, bytes32 leaf);
event LeavesInserted(bytes32 root, uint256 count, bytes32[] leaves);
event LifetimeExtended(bytes32 indexed ticketId, uint256 newTimeout);
event LimitParamsUpdated(UpdateLimitParams[] updates);
event LiquidationCreated();
event LiquidityFeeNumeratorUpdated(uint256 liquidityFeeNumerator, address caller);
event LiquidityLayerAdapterSet(string indexed bridge, address adapter);
event ListingCapUpdate(uint16 newListingCap);
event ListingFeeTokenUpdate(ITrustedTransfarableERC20 indexed newListingFeeToken, uint256 newListingFee);
event ListingFeeUpdate(uint256 newListingFee);
event Lockdown(address indexed owner, address token, address spender);
event LockedThresholdsUpdated(address[] tokens, uint256[] thresholds);
event LogAssetConfigurationApplied(uint256 assetId, bytes32 configHash);
event LogAssetConfigurationRegistered(uint256 assetId, bytes32 configHash);
event LogAssetConfigurationRemoved(uint256 assetId, bytes32 configHash);
event LogBool(bool val);
event LogBridgeActivated();
event LogDebug(uint256 val);
event LogDepositCancel(uint256 starkKey, uint256 vaultId, uint256 assetId);
event LogForcedWithdrawalRequest(uint256 starkKey, uint256 vaultId, uint256 quantizedAmount);
event LogFrozen();
event LogGas(string name, uint256 val);
event LogGlobalConfigurationApplied(bytes32 configHash);
event LogGlobalConfigurationRegistered(bytes32 configHash);
event LogGlobalConfigurationRemoved(bytes32 configHash);
event LogMemoryPageFactContinuous(bytes32 factHash, uint256 memoryHash, uint256 prod);
event LogMemoryPageFactRegular(bytes32 factHash, uint256 memoryHash, uint256 prod);
event LogMemoryPagesHashes(bytes32 factHash, bytes32[] pagesHashes);
event LogMessageToL1(uint256 indexed fromAddress, address indexed toAddress, uint256[] payload);
event LogNewGovernorAccepted(address acceptedGovernor);
event LogNftWithdrawalAllowed(uint256 starkKey, uint256 assetId);
event LogNominatedGovernor(address nominatedGovernor);
event LogNominationCancelled();
event LogOperatorAdded(address operator);
event LogOperatorRemoved(address operator);
event LogRegistered(address entry, string entryId);
event LogRemovalIntent(address entry, string entryId);
event LogRemoved(address entry, string entryId);
event LogRemovedGovernor(address removedGovernor);
event LogScriptCall(address indexed sender, address indexed src, address indexed dst);
event LogSetL2TokenBridge(uint256 value);
event LogSetMaxDeposit(uint256 value);
event LogSetMaxTotalBalance(uint256 value);
event LogStateTransitionFact(bytes32 stateTransitionFact);
event LogStateUpdate(uint256 globalRoot, int256 blockNumber, uint256 blockHash);
event LogSystemAssetType(uint256 assetType);
event LogTokenAdminAdded(address tokenAdmin);
event LogTokenAdminRemoved(address tokenAdmin);
event LogTokenRegistered(uint256 assetType, bytes assetInfo);
event LogUnFrozen();
event LogUserAdminAdded(address userAdmin);
event LogUserAdminRemoved(address userAdmin);
event LogUserRegistered(address ethKey, uint256 starkKey, address sender);
event LogValue(bytes32 val);
event LogWithdrawal(address indexed recipient, uint256 amount);
event MailboxSet(address indexed mailbox);
event ManagerChanged(address indexed account, address indexed newManager);
event MaxDelayBlocksUpdated(uint256 newValue);
event MaxDelaySecondsUpdated(uint256 newValue);
event MaxDelayUpdated(uint256 newMaxDelayBlocks, uint256 newMaxDelaySeconds);
event MaxGasCapUpdated(uint256 _previous, uint256 _updated);
event MaxPacketLengthSet(uint256 maxPacketLength);
event MaxRoutersPerTransferUpdated(uint256 maxRoutersPerTransfer, address caller);
event MaxSubmissionCapUpdated(uint256 _previous, uint256 _updated);
event MessageClaimed(bytes32 indexed _messageHash);
event MessageFailed(uint16 _srcChainId, bytes _srcAddress, uint64 _nonce, bytes _payload, bytes _reason);
event MessageProcessed(bytes data, address caller);
event MessageProven(bytes32 indexed leaf, bytes32 indexed aggregateRoot, uint256 aggregateIndex);
event MessageRelayed(address target, bytes message);
event MessageSent(bytes data, bytes encodedData, address caller);
event MessageSent(bytes message);
event MinDelayChange(uint256 oldDuration, uint256 newDuration);
event MinDisputeBlocksUpdated(uint256 previous, uint256 updated);
event MinimumWaitTimeSet(uint256 minimumWaitTime);
event Mint(address indexed account, uint256 amount);
event Mint(address indexed account, uint256 tokenId);
event Mint(address indexed sender, uint amount0, uint amount1);
event MintLimiterTransferred(address indexed previousGovernance, address indexed newGovernance);
event Minted(address indexed operator, address indexed to, uint256 amount, bytes data, bytes operatorData);
event MinterAdded(address minter_address);
event MinterRemoved(address minter_address);
event MirrorConnectorUpdated(address previous, address current);
event NativeBP(uint bp);
event NewAdmin(address indexed newAdmin);
event NewAdmin(address indexed oldAdmin, address indexed newAdmin);
event NewAdmin(address newAdmin);
event NewAdminFee(bytes32 indexed key, uint256 newAdminFee);
event NewAdminFee(uint256 newAdminFee);
event NewAppProxy(address proxy, bool isUpgradeable, bytes32 appId);
event NewCloneToken(address indexed _cloneToken, uint _snapshotBlock);
event NewContractRegistered(address indexed contractAddress, address indexed creator, address[] parties);
event NewDelay(uint indexed newDelay);
event NewDelay(uint256 delay);
event NewDepositBox(address indexed user);
event NewExecutionDelay(uint256 _newExecutionDelay);
event NewFactoryCloneToken(address indexed _cloneToken, address indexed _parentToken, uint _snapshotBlock);
event NewFeeParams(FeeParams oldFeeParams, FeeParams newFeeParams);
event NewFinalFee(FixedPoint.Unsigned newFinalFee);
event NewFixedOracleFeePerSecondPerPfc(FixedPoint.Unsigned newOracleFee);
event NewGovernor(address indexed oldGovernor, address indexed newGovernor);
event NewGovernor(address newGovernor);
event NewInflationOwner(address);
event NewLibraryVersionAdded(uint16 version);
event NewPendingAdmin(address indexed newPendingAdmin);
event NewPendingAdmin(address indexed oldPendingAdmin, address indexed newPendingAdmin);
event NewPendingAdmin(address newPendingAdmin);
event NewPendingGovernor(address indexed oldPendingGovernor, address indexed newPendingGovernor);
event NewPriorityPeriod(uint256 priorityPeriod);
event NewPriorityTxMaxGasLimit(uint256 oldPriorityTxMaxGasLimit, uint256 newPriorityTxMaxGasLimit);
event NewProposal(uint256 indexed id, Transaction[] transactions);
event NewSponsor(address indexed sponsor);
event NewSwapFee(bytes32 indexed key, uint256 newSwapFee);
event NewSwapFee(uint256 newSwapFee);
event NewToken(address indexed token, uint16 indexed tokenId);
event NewTokenGovernance(TokenGovernance newTokenGovernance);
event NewUpgradable(uint256 indexed versionId, address indexed upgradeable);
event NewValidator(address _oldValidator, address _newValidator);
event NewWeeklyDelayFeePerSecondPerPfc(FixedPoint.Unsigned newWeeklyDelayFeePerSecondPerPfc);
event NewWithdrawFee(uint256 newWithdrawFee);
event NodeConfirmed(uint64 indexed nodeNum, bytes32 blockHash, bytes32 sendRoot);
event NodeRejected(uint256 indexed nodeNum);
event NodeRejected(uint64 indexed nodeNum);
event NoticePeriodChange(uint256 newNoticePeriod);
event Notified(bytes callData, address[] registers, bool[] statuses, bytes[] returnDatas);
event NullEvent();
event ObsoleteRollupType(uint32 indexed rollupTypeID);
event OnSequenceBatches(uint32 indexed rollupID, uint64 lastBatchSequenced);
event OneStepProofCompleted(uint64 indexed challengeIndex);
event OperationCancelled(bytes32 indexed _id);
event OperationExecuted(bytes32 indexed _id);
event OperatorshipTransferred(address[] newOperators, uint256[] newWeights, uint256 newThreshold);
event OperatorshipTransferred(address[] preOperators, uint256 prevThreshold, address[] newOperators, uint256 newThreshold);
event OperatorshipTransferred(bytes newOperatorsData);
event OptimismMintableERC20Created(address indexed localToken, address indexed remoteToken, address deployer);
event OptimisticGovernorDeployed(address indexed owner, address indexed avatar, address target);
event OptimisticModeActivated();
event OptimisticOracleChanged(address indexed newOptimisticOracleV3);
event OutboxToggle(address indexed outbox, bool enabled);
event OutputsDeleted(uint256 indexed prevNextOutputIndex, uint256 indexed newNextOutputIndex);
event Owner(uint256, address);
event OwnerChanged(address oldOwner, address newOwner);
event OwnerClaimed(address indexed claimer);
event OwnerFunctionCalled(uint256 indexed id);
event OwnerNominated(address indexed nominee);
event OwnerNominated(address newOwner);
event OwnerUpdate(address _prevOwner, address _newOwner);
event OwnerUpdated(address newOwner);
event OwnershipProposed(address indexed proposedOwner);
event OwnershipTransferStarted(address indexed newOwner);
event OwnershipTransferStarted(address indexed previousOwner, address indexed newOwner);
event OwnershipTransferred(address indexed _oldOwner, address indexed _newOwner);
event OwnershipTransferred(address indexed newOwner);
event OwnershipTransferred(address indexed previousOwner, address indexed newOwner);
event OwnershipTransferred(address[] preOwners, uint256 prevThreshold, address[] newOwners, uint256 newThreshold);
event Packet(bytes payload);
event PacketReceived(uint16 indexed srcChainId, bytes srcAddress, address indexed dstAddress, uint64 nonce, bytes32 payloadHash);
event PartyAdded(address indexed contractAddress, address indexed party);
event PartyRemoved(address indexed contractAddress, address indexed party);
event PathTripChanged(uint32 srcChainSlug, bool isPathTripped);
event Paused();
event Paused(address account);
event Paused(string identifier);
event PausedDeposits(bool isPaused);
event PausedFills(bool isPaused);
event PauserChanged(address indexed previousPauser, address indexed newPauser);
event PayloadCleared(uint16 srcChainId, bytes srcAddress, uint64 nonce, address dstAddress);
event PayloadStored(uint16 srcChainId, bytes srcAddress, address dstAddress, uint64 nonce, bytes payload, bytes reason);
event PendingAggregateRootDeleted(bytes32 indexed aggregateRoot);
event PositionCreated(address indexed sponsor, uint256 indexed collateralAmount, uint256 indexed tokenAmount);
event PredicateAdded(address indexed predicate, address indexed from);
event PredicateRemoved(address indexed predicate, address indexed from);
event PreparationStart(uint256 indexed versionId);
event PriceRequestAdded(uint256 indexed roundId, bytes32 indexed identifier, uint256 time);
event PriorityControllerUpdated(address account, bool isPriorityController);
event Process(bytes32 indexed leaf, bool success, bytes returnData);
event ProcessId(bytes32 indexed messageId);
event ProofValidatorAdded(address indexed validator, address indexed from);
event ProofValidatorRemoved(address indexed validator, address indexed from);
event PropagateFailed(uint32 domain, address connector);
event ProposalApproved(bytes32 indexed proposalHash);
event ProposalCanceled(uint256 id);
event ProposalDeleted(bytes32 indexed proposalHash, bytes32 indexed assertionId);
event ProposalExecuted(bytes32 indexed proposalHash, bool[] successCalls, bytes[] returnDatas);
event ProposalExecuted(bytes32 indexed proposalHash, bytes32 indexed assertionId);
event ProposalExecuted(uint256 id, address indexed initiatorExecution);
event ProposalExecuted(uint256 indexed id, uint256 transactionIndex);
event ProposalExpired(bytes32 indexed proposalHash);
event ProposalExpiryDurationChanged(uint256 indexed duration);
event ProposalQueued(uint256 id, uint256 executionTime, address indexed initiatorQueueing);
event ProposalRejected(bytes32 indexed proposalHash);
event ProposalResolved(uint256 indexed id, bool success);
event ProposalTripped(bytes32 packetId, uint256 proposalCount);
event ProposalVoted(bytes32 indexed proposalHash, address indexed voter, Ballot.VoteType support, uint256 weight);
event ProposedRootFinalized(bytes32 aggregateRoot);
event ProposerAdded(address indexed proposer);
event ProposerModified(address proposer, bool enabled);
event ProposerRemoved(address indexed proposer);
event ProtocolFeeVaultChanged (address feeVaultAddress);
event ProxyDeposit(address sender, uint256 value);
event ProxyOssified();
event ProxyUpdated(address indexed _new, address indexed _old);
event QueryReturned(uint32 indexed originDomain, address indexed sender);
event QueueTransaction(bytes32 indexed txHash, address indexed target, uint value, string signature, bytes data, uint eta);
event QuorumSet(uint256 quorum);
event RampA(uint256 oldA, uint256 newA, uint256 initialTime, uint256 futureTime);
event RampAStarted(bytes32 indexed key, uint256 futureA, uint256 futureTime, address caller);
event RampAStopped(bytes32 indexed key, address caller);
event ReadFieldElementEvent(uint256 val);
event ReadHashEvent(bytes32 val);
event ReadyToProve(uint256 indexed outputIndex, address indexed challenger);
event Receive(address indexed token, address indexed to, uint amountLD);
event ReceivedAddressResult(address result);
event ReceivedBytes32Result(bytes32 result);
event ReceivedCall(address indexed caller, uint256 amount, string message);
event ReceivedUint256Result(uint256 result);
event RecoverToVault(address indexed vault, address indexed token, uint256 amount);
event Redeem(address indexed sponsor, uint256 indexed collateralAmount, uint256 indexed tokenAmount);
event Redeemed(bytes32 indexed userTxHash);
event RedeemedEvent(address caller, address redeemer);
event RedemptionCancelled(address indexed user, uint256 indexed index);
event RedemptionCompleted(address indexed user, uint256 indexed index);
event RedemptionStarted(address indexed user, uint256 indexed index);
event RedemptionStatusChanged(bool isActive);
event RefundAddressUpdated(address indexed previous, address indexed updated);
event RefundERC1155(address indexed token, address indexed recipient, uint256 tokenId, uint256 amount);
event RefundERC20(address indexed token, address indexed recipient, uint256 amount);
event RefundERC721(address indexed token, address indexed recipient, uint256 tokenId);
event RefundETH(address indexed recipient, uint256 amount);
event RegisterToken(address token);
event RegularFeesPaid(uint256 indexed regularFee, uint256 indexed lateFee);
event RelayedMessage(bytes32 indexed messageHash);
event RelayedMessage(bytes32 indexed msgHash);
event RelayedMessage(bytes32 msgHash);
event RelayerAdded(address relayer, address caller);
event RelayerFeeVaultUpdated(address oldVault, address newVault, address caller);
event RelayerParams(bytes adapterParams, uint16 outboundProofType);
event RelayerRemoved(address relayer, address caller);
event Rely(address indexed usr);
event RemoteAdded(uint32 domain, address remote, address caller);
event RemoteRouterEnrolled(uint32 indexed domain, bytes32 indexed router);
event RemoveLiquidity(address indexed provider, uint256[] tokenAmounts, uint256 lpTokenSupply);
event RemoveLiquidity(bytes32 indexed key, address indexed provider, uint256[] tokenAmounts, uint256 lpTokenSupply);
event RemovedFromWhitelist(address indexed removedAddress);
event RemovedOwner(address owner);
event RemovedSharedMember(uint256 indexed roleId, address indexed oldMember, address indexed manager);
event Repay(address indexed sponsor, uint256 indexed numTokensRepaid, uint256 indexed newTokenCount);
event RequestTransferPosition(address indexed oldSponsor);
event RequestTransferPositionCanceled(address indexed oldSponsor);
event RequestTransferPositionExecuted(address indexed oldSponsor, address indexed newSponsor);
event RequestWithdrawal(address indexed sponsor, uint256 indexed collateralAmount);
event RequestWithdrawal(address indexed user, uint256 indexed collateralAmount, uint256 requestPassTimestamp);
event RequestWithdrawalCanceled(address indexed sponsor, uint256 indexed collateralAmount);
event RequestWithdrawalExecuted(address indexed sponsor, uint256 indexed collateralAmount);
event ResetExclusiveMember(uint256 indexed roleId, address indexed newMember, address indexed manager);
event RetryMessageSuccess(uint16 _srcChainId, bytes _srcAddress, uint64 _nonce, bytes32 _payloadHash);
event RetryableTicketCreated(uint256 indexed ticketId);
event RevertBatch(uint256 indexed batchIndex, bytes32 indexed batchHash);
event RevokeAccess(bytes32 indexed role, address indexed target, bytes4[] selectors);
event RevokeRole(address revokedAddress, Role revokedRole);
event RevokedOperator(address indexed operator, address indexed tokenHolder);
event RoleAdminChanged(bytes32 indexed role, bytes32 indexed previousAdminRole, bytes32 indexed newAdminRole);
event RoleGranted(bytes32 indexed role, address indexed account, address indexed sender);
event RoleGranted(bytes32 indexed role, address indexed grantee);
event RoleRevoked(bytes32 indexed role, address indexed account, address indexed sender);
event RoleRevoked(bytes32 indexed role, address indexed revokee);
event RollupCreated(bytes32 machineHash);
event RollupInitialized(bytes32 machineHash, uint256 chainId);
event RollupUpdated(address rollup);
event RootDiscarded(bytes32 fraudulentRoot);
event RootReceived(bytes32 packetId, bytes32 root);
event RootReceived(uint32 domain, bytes32 receivedRoot, uint256 queueIndex);
event RootUpdatesPaused();
event RootUpdatesUnpaused();
event RouterAdded(address indexed router, address caller);
event RouterAllowlistRemovalProposed(uint256 timestamp);
event RouterAllowlistRemoved(bool renounced);
event RouterApprovedForPortal(address router, address caller);
event RouterInitialized(address indexed router);
event RouterLiquidityAdded(address indexed router, address local, bytes32 key, uint256 amount, address caller);
event RouterOwnerAccepted(address indexed router, address indexed prevOwner, address indexed newOwner);
event RouterOwnerProposed(address indexed router, address indexed prevProposed, address indexed newProposed);
event RouterRecipientSet(address indexed router, address indexed prevRecipient, address indexed newRecipient);
event RouterRemoved(address indexed router, address caller);
event RouterUnapprovedForPortal(address router, address caller);
event SafeModuleTransaction(address module, address to, uint256 value, bytes data, Enum.Operation operation);
event SafeReceived(address indexed sender, uint256 value);
event SafeSetup(address indexed initiator, address[] owners, uint256 threshold, address initializer, address fallbackHandler);
event ScriptResult(address indexed executor, bytes script, bytes input, bytes returnData);
event Send(address indexed token, address indexed from, bytes32 indexed to, uint amountLD);
event SendEvent(uint64 indexed sequence, uint256 deliveryQuote, uint256 paymentForExtraReceiverValue);
event SendMerkleUpdate(uint256 indexed reserved, bytes32 indexed hash, uint256 indexed position);
event SendRandomnessEvent(uint256 val);
event SendRateLimitUpdated(address updater, uint256 newRateLimit);
event SendRootUpdated(bytes32 indexed blockHash, bytes32 indexed outputRoot);
event SendRootUpdated(bytes32 indexed outputRoot, bytes32 indexed l2BlockHash);
event SenderAdded(address indexed sender);
event SenderRemoved(address indexed sender);
event SentMessage(address indexed target, address sender, bytes message, uint256 messageNonce, uint256 gasLimit);
event SentMessage(bytes message);
event SentMessageExtension1(address indexed sender, uint256 value);
event SequenceBatches(uint64 indexed numBatch);
event SequenceBatches(uint64 indexed numBatch, bytes32 l1InfoRoot);
event SequenceForceBatches(uint64 indexed numBatch);
event SequencerAdded(address sequencer, address caller);
event SequencerAddressUpdated(address newAddress);
event SequencerBatchData(uint256 indexed batchSequenceNumber, bytes data);
event SequencerInboxUpdated(address newSequencerInbox);
event SequencerRemoved(address sequencer, address caller);
event SetApp(bytes32 indexed namespace, bytes32 indexed appId, address app);
event SetAptosChainId(uint16 aptosChainId);
event SetBatchFee(uint256 newBatchFee);
event SetBridgeBP(uint bridgeFeeBP);
event SetChainAddressSize(uint16 indexed chainId, uint size);
event SetCollateralAndBond(IERC20 indexed collateral, uint256 indexed bondAmount);
event SetDataAvailabilityProtocol(address newDataAvailabilityProtocol);
event SetDefaultAdapterParamsForChainId(uint16 indexed chainId, uint16 indexed proofType, bytes adapterParams);
event SetDefaultConfigForChainId(uint16 indexed chainId, uint16 inboundProofLib, uint64 inboundBlockConfirm, address relayer, uint16 outboundProofType, uint64 outboundBlockConfirm, address oracle);
event SetDefaultERC20Gateway(address indexed oldDefaultERC20Gateway, address indexed newDefaultERC20Gateway);
event SetDefaultNFTFactory(address indexed factory);
event SetDepositQuoteTimeBuffer(uint32 newBuffer);
event SetERC20Gateway(address indexed token, address indexed oldGateway, address indexed newGateway);
event SetETHGateway(address indexed oldETHGateway, address indexed newEthGateway);
event SetEscalationManager(address indexed escalationManager);
event SetForceBatchAddress(address newForceBatchAddress);
event SetForceBatchTimeout(uint64 newforceBatchTimeout);
event SetGlobalPause(bool paused);
event SetHubPool(address indexed newHubPool);
event SetIdentifier(bytes32 indexed identifier);
event SetLayerZeroToken(address indexed tokenAddress);
event SetLiveness(uint64 indexed liveness);
event SetLocalChainId(uint16 localChainId);
event SetMinDstGas(uint16 _dstChainId, uint16 _type, uint _minDstGas);
event SetMultiplierBatchFee(uint16 newMultiplierBatchFee);
event SetPendingStateTimeout(uint64 newPendingStateTimeout);
event SetPermission(address indexed entity, address indexed app, bytes32 indexed role, bool allowed);
event SetPermissionParams(address indexed entity, address indexed app, bytes32 indexed role, bytes32 paramsHash);
event SetPrecrime(address precrime);
event SetRemoteUln(uint16 indexed chainId, bytes32 uln);
event SetRules(string rules);
event SetTokenPause(address token, bool paused);
event SetTreasury(address indexed treasuryAddress);
event SetTrustedAggregator(address newTrustedAggregator);
event SetTrustedAggregatorTimeout(uint64 newTrustedAggregatorTimeout);
event SetTrustedRemote(uint16 _remoteChainId, bytes _path);
event SetTrustedRemoteAddress(uint16 _remoteChainId, bytes _remoteAddress);
event SetTrustedSequencer(address newTrustedSequencer);
event SetTrustedSequencerURL(string newTrustedSequencerURL);
event SetUseCustomAdapterParams(bool useCustomAdapterParams);
event SetValidKeyset(bytes32 indexed keysetHash, bytes keysetBytes);
event SetVerifyBatchTimeTarget(uint64 newVerifyBatchTimeTarget);
event SetWETH(address weth);
event SetXDomainAdmin(address indexed newAdmin);
event SettingsUpdated(uint time);
event ShadowOperationScheduled(bytes32 indexed _id, uint256 delay);
event ShutdownForNitroSet(bool shutdown);
event SignMsg(bytes32 indexed msgHash);
event SignatureVerifierSet(address signatureVerifier);
event SignersRotated(address[] newAccounts, uint256 newThreshold);
event SlippageUpdated(bytes32 indexed transferId, uint256 slippage);
event SlotFound(address who, bytes4 fsig, bytes32 keysHash, uint256 slot);
event SlowModeActivated(address indexed watcher);
event Snapshot(uint256 id);
event SnapshotRootSaved(uint256 indexed snapshotId, bytes32 indexed root, uint256 indexed count);
event SocketSet(address newSocket);
event StandardL2TokenCreated(address indexed remoteToken, address indexed localToken);
event StartVote(uint256 indexed voteId, address indexed creator, string metadata);
event StateBatchDeleted(uint256 indexed _batchIndex, bytes32 _batchRoot);
event StopRampA(uint256 currentA, uint256 time);
event SubmitPaused(bool new_status);
event SupportedIdentifierAdded(bytes32 indexed identifier);
event SupportedIdentifierRemoved(bytes32 indexed identifier);
event SwapDisabled(bytes32 indexed key, address caller);
event SwapFeesSet(bytes32 indexed key, uint256 newSwapFee, address caller);
event SwapInitialized(bytes32 indexed key, SwapUtils.Swap swap, address caller);
event SwapRemoved(bytes32 indexed key, address caller);
event SwitchSequenceWithDataAvailability();
event SwitchboardFeesSet(uint32 siblingChainSlug, Fees fees);
event Sync(uint112 reserve0, uint112 reserve1);
event TargetCallExecuted(address indexed target, uint256 value, bytes data);
event TargetOptionUpdated(GlobalProposal.TargetOption indexed targetOption, address indexed addr);
event TargetSet(address indexed previousTarget, address indexed newTarget);
event TargetUpdated(address newTarget);
event TemplateUpdated();
event TemplatesUpdated();
event ThresholdSet(uint32 indexed domain, uint8 threshold);
event TicketCreated(bytes32 indexed ticketId);
event TimelockChanged(address timelock_address);
event TokenAdded(address indexed token, string indexed symbol);
event TokenDeployed(string symbol, address tokenAddresses);
event TokenDeployed(uint32 indexed domain, bytes32 indexed id, address indexed representation);
event TokenFrozen(string indexed symbol);
event TokenListerUpdate(address indexed tokenLister, bool isActive);
event TokenMapped(address indexed rootToken, address indexed childToken);
event TokenMapped(address[] mainchainTokens, address[] roninTokens, Token.Standard[] standards);
event TokenMintLimitUpdated(string symbol, uint256 limit);
event TokenMinterBurned(address indexed from, address indexed to, uint256 amount);
event TokenMinterMinted(address indexed from, address indexed to, uint256 amount);
event TokenPausedUpdate(address indexed token, bool paused);
event TokenRemoved(address indexed token, string indexed symbol);
event TokenSent(address indexed sender, string destinationChain, string destinationAddress, string symbol, uint256 amount);
event TokenSet(address indexed l1Address, address indexed l2Address);
event TokenSold(address token, uint amount);
event TokenSwap(address indexed buyer, uint256 tokensSold, uint256 tokensBought, uint128 soldId, uint128 boughtId);
event TokenUnfrozen(string indexed symbol);
event TokensMinted(address connecter, address receiver, uint256 mintAmount);
event TokensRelayed(address l1Token, address l2Token, uint256 amount, address to);
event TotalProtocolDAIUpdated(uint256 newAmount);
event TransactionDeposited(address indexed from, address indexed to, uint256 indexed version, bytes opaqueData);
event Transfer(address indexed _from, address indexed _to, uint256 _amount);
event Transfer(address indexed from, address indexed to, uint value);
event Transfer(address indexed from, address indexed to, uint256 amount);
event Transfer(address indexed from, address indexed to, uint256 indexed tokenId);
event Transfer(address indexed from, address indexed to, uint256 value);
event Transfer(address indexed from, address indexed to, uint256 value, bytes data);
event Transfer(address indexed src, address indexed dst, uint256 wad);
event TransferAdminRole(address newPendingAdmin);
event TransferRelayerFeesIncreased(bytes32 indexed transferId, uint256 increase, address asset, address caller);
event TransferSingle(address indexed operator, address indexed from, address indexed to, uint256 id, uint256 value);
event TransmissionFeesSet(uint256 dstChainSlug, uint256 transmissionFees);
event TransmitManagerSet(address transmitManager);
event TransparentOperationScheduled(bytes32 indexed _id, uint256 delay, Operation _operation);
event TreasuryUpdate(address newTreasury);
event TrustedForwarderChanged(address indexed _tf);
event TxToL1(address indexed _from, address indexed _to, uint256 indexed _id, bytes _data);
event TxToL2(address indexed _from, address indexed _to, uint256 indexed _seqNum, bytes _data);
event TxToL2(address indexed from, address indexed to, uint256 indexed seqNum, bytes data);
event URI(string value, uint256 indexed id);
event UaForceResumeReceive(uint16 chainId, bytes srcAddress);
event UaReceiveVersionSet(address ua, uint16 version);
event UaSendVersionSet(address ua, uint16 version);
event Unfreeze();
event Unfrozen(address indexed owner);
event UnlockFeePercentagesUpdated(address[] tokens, uint256[] percentages);
event UnorderedNonceInvalidation(address indexed owner, uint256 word, uint256 mask);
event Unpaused();
event Unpaused(address account);
event UpdateDetails(string indexed name, string indexed symbol);
event UpdateEnforcedTxGateway(address indexed _oldGateway, address indexed _newGateway);
event UpdateFeeVault(address _oldFeeVault, address _newFeeVault);
event UpdateGasOracle(address indexed _oldGasOracle, address indexed _newGasOracle);
event UpdateMaxGasLimit(uint256 _oldMaxGasLimit, uint256 _newMaxGasLimit);
event UpdateMaxNumTxInChunk(uint256 oldMaxNumTxInChunk, uint256 newMaxNumTxInChunk);
event UpdateMaxReplayTimes(uint256 oldMaxReplayTimes, uint256 newMaxReplayTimes);
event UpdateProver(address indexed account, bool status);
event UpdateSequencer(address indexed account, bool status);
event UpdateTokenMapping(address indexed l1Token, address indexed oldL2Token, address indexed newL2Token);
event UpdateTotalLimit(address indexed token, uint256 oldTotalLimit, uint256 newTotalLimit);
event UpdateVerifier(address indexed oldVerifier, address indexed newVerifier);
event UpdateVerifier(uint256 startBatchIndex, address verifier);
event UpdateWhitelist(address _oldWhitelist, address _newWhitelist);
event UpdateZkEVMVersion(uint64 numBatch, uint64 forkID, string version);
event UpdatedActionPriorityStatus(bytes32 actionHash, bool isUnlockedForExecution);
event UpdatedBridge(address bridgeAddress);
event UpdatedInboxAddress(address inbox);
event UpdatedOutbox(address outboxAddress);
event UpdatedReceiveGasLimit(uint256 receiveGasLimit);
event UpdatedRemoteNativeSwitchboard(address remoteNativeSwitchboard);
event UpgradeCancel(uint256 indexed versionId);
event UpgradeComplete(uint256 indexed versionId, address[] newTargets);
event UpgradeExecuted(address indexed upgrade, uint256 value, bytes data);
event Upgraded(address indexed implementation);
event UpgradedSecondary(address indexed implementation);
event UserStakeUpdated(address indexed user, uint256 initialBalance, uint256 finalBalance);
event ValidatorAdded(bytes pubKey, bytes withdrawalCredential);
event ValidatorArrayCleared();
event ValidatorRemoved(bytes pubKey, uint256 remove_idx, bool dont_care_about_ordering);
event ValidatorStatusUpdate(address indexed validatorAddress, bool isActive);
event ValidatorsPopped(uint256 times);
event ValidatorsSwapped(bytes from_pubKey, bytes to_pubKey, uint256 from_idx, uint256 to_idx);
event VoteEmitted(uint256 id, address indexed voter, bool support, uint256 votingPower);
event VotingDelayChanged(uint256 newVotingDelay, address indexed initiatorChange);
event WARNING_UninitedSlot(address who, uint256 slot);
event WatcherAdded(address watcher);
event WatcherManagerChanged(address watcherManager);
event WatcherRemoved(address watcher);
event WhitelistSourceUpdated(address newSource);
event WhitelistStatusChanged(address indexed _account, bool _status);
event WhitelistUpdated(address account, bool isAdded);
event WhitelistUpgraded(address newWhitelist, address[] targets);
event WithdrawETH(address indexed from, address indexed to, uint256 amount, bytes data);
event WithdrawFee(address indexed token, address to, uint amountLD);
event WithdrawNative(address indexed msgSender, address indexed to, uint amount);
event WithdrawRewards(address indexed owner, uint256 amount, address indexed currency);
event WithdrawTVL(address indexed token, address to, uint amountLD);
event WithdrawZRO(address indexed msgSender, address indexed to, uint amount);
event Withdrawal(address indexed owner, uint16 indexed tokenId, uint128 amount);
event Withdrawal(address indexed sponsor, uint256 indexed collateralAmount);
event Withdrawal(address indexed src, uint256 wad);
event WithdrawalCredentialSet(bytes _withdrawalCredential);
event WithdrawalFinalized(address indexed to, address indexed l1Token, uint256 amount);
event WithdrawalFinalized(bytes32 indexed withdrawalHash, bool success);
event WithdrawalLocked(bytes32 receiptHash, Transfer.Receipt receipt);
event WithdrawalNFT(uint32 indexed tokenId);
event WithdrawalNFTPending(uint32 indexed tokenId);
event WithdrawalProven(bytes32 indexed withdrawalHash, address indexed from, address indexed to);
event WithdrawalUnlocked(bytes32 receiptHash, Transfer.Receipt receipt);
event WithdrawalsDisabled(address indexed disabler);
event WithdrawalsEnabled(address indexed enabler);
event Withdrew(bytes32 receiptHash, Transfer.Receipt receipt);
event WithheldETHMoved(address indexed to, uint256 amount);
event WithholdRatioSet(uint256 newRatio);
event WrappedNativeTokenContractUpdated(IWETH weth);
event XAppConnectionManagerSet(address updated, address caller);
event XaiAddressChanged(address indexed newXaiAddress);
event YieldClaimed(address indexed beneficiary, uint256 amount);
event ZkSyncMessageRelayed(bytes32 canonicalTxHash);
event ZroEnabled(bool zroEnabled);
event ZroFee(uint zroFee);
event log                    (string);
event log_address            (address);
event log_array(address[] val);
event log_array(int256[] val);
event log_array(uint256[] val);
event log_bytes              (bytes);
event log_bytes32            (bytes32);
event log_int                (int);
event log_named_address      (string key, address val);
event log_named_array(string key, address[] val);
event log_named_array(string key, int256[] val);
event log_named_array(string key, uint256[] val);
event log_named_bytes        (string key, bytes val);
event log_named_bytes32      (string key, bytes32 val);
event log_named_decimal_int  (string key, int val, uint decimals);
event log_named_decimal_uint (string key, uint val, uint decimals);
event log_named_int          (string key, int val);
event log_named_string       (string key, string val);
event log_named_uint         (string key, uint val);
event log_string             (string);
event log_uint               (uint);
event logs                   (bytes);


error AccessControlOnlyCanRenounceRolesForSelf();
error AddressDoNotHaveRequiredRole();
error AddressEmptyCode(address target);
error AddressInsufficientBalance(address account);
error AllowanceExpired(uint256 deadline);
error AllzkEVMSequencedBatchesMustBeVerified();
error AlreadyAttested();
error AlreadyClaimed();
error AlreadyInit();
error AlreadyInitialized();
error AlreadyPaused();
error AlreadySpent(uint256 index);
error AlreadyUnpaused();
error AlreadyValidDASKeyset(bytes32);
error AlreadyVoted();
error AmountDoesNotMatchMsgValue();
error AmountOutsideLimit();
error AssetLogic__getConfig_notRegistered();
error AssetLogic__getTokenIndexFromStableSwapPool_notExist();
error AssetLogic__handleIncomingAsset_feeOnTransferNotSupported();
error AssetLogic__handleIncomingAsset_nativeAssetNotSupported();
error AssetLogic__handleOutgoingAsset_notNative();
error AssetLogic__swapAsset_externalStableSwapPoolDoesNotExist();
error BadArrayLength(uint256 expected, uint256 actual);
error BadPostUpgradeInit();
error BadSequencerMessageNumber(uint256 stored, uint256 received);
error BadSequencerNumber(uint256 stored, uint256 received);
error BaseConnextFacet__getAdoptedAsset_assetNotFound();
error BaseConnextFacet__getApprovedCanonicalId_notAllowlisted();
error BaseConnextFacet__nonReentrant_reentrantCall();
error BaseConnextFacet__nonXCallReentrant_reentrantCall();
error BaseConnextFacet__onlyOwnerOrAdmin_notOwnerOrAdmin();
error BaseConnextFacet__onlyOwnerOrRouter_notOwnerOrRouter();
error BaseConnextFacet__onlyOwnerOrWatcher_notOwnerOrWatcher();
error BaseConnextFacet__onlyOwner_notOwner();
error BaseConnextFacet__onlyProposed_notProposedOwner();
error BaseConnextFacet__whenNotPaused_paused();
error BatchAlreadyVerified();
error BatchFeeOutOfRange();
error BatchNotSequencedOrNotSequenceEnd();
error BeneficiaryInvalid(address newBeneficiary);
error BridgeAmountInvalid();
error BridgeCallFailed();
error BridgeFacet__addRemote_invalidDomain();
error BridgeFacet__addRemote_invalidRouter();
error BridgeFacet__addSequencer_alreadyApproved();
error BridgeFacet__addSequencer_invalidSequencer();
error BridgeFacet__bumpTransfer_noRelayerVault();
error BridgeFacet__bumpTransfer_valueIsZero();
error BridgeFacet__excecute_insufficientGas();
error BridgeFacet__executePortalTransfer_insufficientAmountWithdrawn();
error BridgeFacet__execute_badFastLiquidityStatus();
error BridgeFacet__execute_externalCallFailed();
error BridgeFacet__execute_invalidRouterSignature();
error BridgeFacet__execute_invalidSequencerSignature();
error BridgeFacet__execute_maxRoutersExceeded();
error BridgeFacet__execute_notApprovedForPortals();
error BridgeFacet__execute_notReconciled();
error BridgeFacet__execute_notSupportedRouter();
error BridgeFacet__execute_notSupportedSequencer();
error BridgeFacet__execute_unapprovedSender();
error BridgeFacet__execute_wrongDomain();
error BridgeFacet__forceReceiveLocal_notDestination();
error BridgeFacet__forceUpdateSlippage_invalidSlippage();
error BridgeFacet__forceUpdateSlippage_notDestination();
error BridgeFacet__mustHaveRemote_destinationNotSupported();
error BridgeFacet__onlyDelegate_notDelegate();
error BridgeFacet__removeSequencer_notApproved();
error BridgeFacet__setXAppConnectionManager_domainsDontMatch();
error BridgeFacet__xcall_capReached();
error BridgeFacet__xcall_emptyTo();
error BridgeFacet__xcall_invalidSlippage();
error BridgeFacet__xcall_nativeAssetNotSupported();
error BridgeFacet_xcall__emptyLocalAsset();
error BurnFailed(string symbol);
error CallNotAllowed();
error CallTargetNotAllowed(address target);
error CapExceeded();
error ChainIDAlreadyExist();
error ConnectorUnavailable();
error Connector__processMessage_notUsed();
error DataNotAuthenticated();
error DataTooLarge(uint256 dataLength, uint256 maxDataLength);
error DelayedBackwards();
error DelayedTooFar();
error DeliveryProviderCannotReceivePayment();
error DeliveryProviderDoesNotSupportTargetChain(address relayer, uint16 chainId);
error DestinationNetworkInvalid();
error DiamondInit__init_alreadyInitialized();
error DiamondInit__init_domainsDontMatch();
error DuplicateOperators();
error DuplicateSigner(address account);
error ECDSAInvalidSignature();
error ECDSAInvalidSignatureLength(uint256 length);
error ECDSAInvalidSignatureS(bytes32 s);
error ERC1155InsufficientBalance(address sender, uint256 balance, uint256 needed, uint256 tokenId);
error ERC1155InvalidApprover(address approver);
error ERC1155InvalidArrayLength(uint256 idsLength, uint256 valuesLength);
error ERC1155InvalidOperator(address operator);
error ERC1155InvalidReceiver(address receiver);
error ERC1155InvalidSender(address sender);
error ERC1155MissingApprovalForAll(address operator, address owner);
error ERC1967InvalidAdmin(address admin);
error ERC1967InvalidBeacon(address beacon);
error ERC1967InvalidImplementation(address implementation);
error ERC1967NonPayable();
error ERC20InsufficientAllowance(address spender, uint256 allowance, uint256 needed);
error ERC20InsufficientBalance(address sender, uint256 balance, uint256 needed);
error ERC20InvalidApprover(address approver);
error ERC20InvalidReceiver(address receiver);
error ERC20InvalidSender(address sender);
error ERC20InvalidSpender(address spender);
error ERC2612ExpiredSignature(uint256 deadline);
error ERC2612InvalidSigner(address signer, address owner);
error ERC721IncorrectOwner(address sender, uint256 tokenId, address owner);
error ERC721InsufficientApproval(address operator, uint256 tokenId);
error ERC721InvalidApprover(address approver);
error ERC721InvalidOperator(address operator);
error ERC721InvalidOwner(address owner);
error ERC721InvalidReceiver(address receiver);
error ERC721InvalidSender(address sender);
error ERC721NonexistentToken(uint256 tokenId);
error EmptyBytecode();
error ErrAddressIsNotCreatedEOA(address addr, bytes32 codehash);
error ErrAlreadyVoted(address voter);
error ErrBridgeOperatorAlreadyExisted(address bridgeOperator);
error ErrBridgeOperatorUpdateFailed(address bridgeOperator);
error ErrCallPrecompiled(bytes4 msgSig);
error ErrCallerMustBeCoinbase();
error ErrContractTypeNotFound(ContractType contractType);
error ErrCurrentProposalIsNotCompleted();
error ErrDuplicated(bytes4 msgSig);
error ErrERC20MintingFailed();
error ErrERC721MintingFailed();
error ErrEmptyArray();
error ErrInSourceValidation();
error ErrInsufficientGas(bytes32 proposalHash);
error ErrInvalidArguments(bytes4 msgSig);
error ErrInvalidChainId(bytes4 msgSig, uint256 actual, uint256 expected);
error ErrInvalidExpiryTimestamp();
error ErrInvalidInfo();
error ErrInvalidOrder(bytes4 msgSig);
error ErrInvalidPercentage();
error ErrInvalidProposalNonce(bytes4 msgSig);
error ErrInvalidReceipt();
error ErrInvalidReceiptKind();
error ErrInvalidRequest();
error ErrInvalidReturnData(bytes4 callbackFnSig, address register, bytes returnData);
error ErrInvalidSignatures(bytes4 msgSig);
error ErrInvalidThreshold(bytes4 msgSig);
error ErrInvalidTokenStandard();
error ErrInvalidVoteHash();
error ErrInvalidVoteWeight(bytes4 msgSig);
error ErrLengthMismatch(bytes4 msgSig);
error ErrNativeTransferFailed(bytes4 msgSig);
error ErrNonpayableAddress(address);
error ErrOncePerBlock();
error ErrOnlySelfCall(bytes4 msgSig);
error ErrPeriodAlreadyProcessed(uint256 requestingPeriod, uint256 latestPeriod);
error ErrProxyCallFailed(bytes4 msgSig, bytes4 extCallSig);
error ErrQueryForApprovedWithdrawal();
error ErrQueryForEmptyVote();
error ErrQueryForExpiredVote();
error ErrQueryForInsufficientVoteWeight();
error ErrQueryForNonExistentVote();
error ErrQueryForOutdatedBridgeOperatorSet();
error ErrQueryForProcessedWithdrawal();
error ErrReachedDailyWithdrawalLimit();
error ErrRelayFailed(bytes4 msgSig);
error ErrSyncTooFarPeriod(uint256 period, uint256 latestRewardedPeriod);
error ErrTokenCouldNotTransfer(Info tokenInfo, address to, address token);
error ErrTokenCouldNotTransferFrom(Info tokenInfo, address from, address to, address token);
error ErrUnauthorized(bytes4 msgSig, RoleAccess expectedRole);
error ErrUnauthorizedCall(bytes4 msgSig);
error ErrUnexpectedInternalCall(bytes4 msgSig, ContractType expectedContractType, address actual);
error ErrUnsupportedInterface(bytes4 interfaceId, address addr);
error ErrUnsupportedStandard();
error ErrUnsupportedTarget(bytes32 proposalHash, uint256 targetNumber);
error ErrUnsupportedToken();
error ErrUnsupportedVoteType(bytes4 msgSig);
error ErrVoteIsFinalized();
error ErrZeroAddress(bytes4 msgSig);
error ErrZeroCodeContract(address addr);
error ErrorAccountIsZeroAddress();
error ErrorAlreadyInitialized();
error ErrorDepositsDisabled();
error ErrorDepositsEnabled();
error ErrorETHValueTooLow();
error ErrorNoMaxSubmissionCost();
error ErrorNotAdmin();
error ErrorProxyIsOssified();
error ErrorSenderNotEOA();
error ErrorUnauthorizedBridge();
error ErrorUnauthorizedMessenger();
error ErrorUnsupportedL1Token();
error ErrorUnsupportedL2Token();
error ErrorWithdrawalsDisabled();
error ErrorWithdrawalsEnabled();
error ErrorWrongCrossDomainSender();
error EtherTransferFailed();
error ExceedMaxVerifyBatches();
error ExceedMintLimit(string symbol);
error ExceedTotalLimit(address token);
error ExcessiveInvalidation();
error ExecutionFailed();
error ExtraDataNotEmpty();
error FailedDeploy();
error FailedInit();
error FailedInnerCall();
error FailedTokenWrappedDeployment();
error FeePaymentFailed(address recipient);
error FeeTooLow();
error FeesNotEnough();
error FeesTooHigh();
error FinalNumBatchBelowLastVerifiedBatch();
error FinalNumBatchDoesNotMatchPendingState();
error FinalPendingStateNumInvalid();
error ForceBatchNotAllowed();
error ForceBatchTimeoutNotExpired();
error ForceBatchesAlreadyActive();
error ForceBatchesDecentralized();
error ForceBatchesNotAllowedOnEmergencyState();
error ForceBatchesOverflow();
error ForceIncludeBlockTooSoon();
error ForceIncludeTimeTooSoon();
error ForcedDataDoesNotMatch();
error ForwardNotSufficientlyFunded(uint256 amountOfFunds, uint256 amountOfFundsNeeded);
error ForwardRequestFromWrongAddress(address msgSender, address deliveryTarget);
error GasLimitTooLarge();
error GasTokenNetworkMustBeZeroOnEther();
error GlobalExitRootInvalid();
error GlobalExitRootNotExist();
error HadZeroInit();
error HaltTimeoutNotExpired();
error HaltTimeoutNotExpiredAfterEmergencyState();
error HugeTokenMetadataNotSupported();
error InboxFacet__handle_notTransfer();
error InboxFacet__onlyRemoteRouter_notRemote();
error InboxFacet__onlyReplica_notReplica();
error InboxFacet__reconcile_alreadyReconciled();
error InboxFacet__reconcile_noPortalRouter();
error IncorrectMessagePreimage();
error InflationRecipientNotWhitelisted(address);
error InitBatchMustMatchCurrentForkID();
error InitNumBatchAboveLastVerifiedBatch();
error InitNumBatchDoesNotMatchPendingState();
error InsufficientAllowance(uint256 amount);
error InsufficientBalance();
error InsufficientFees();
error InsufficientMessageLength();
error InsufficientMsgValue();
error InsufficientRelayerFunds(uint256 msgValue, uint256 minimum);
error InsufficientSubmissionCost(uint256 expected, uint256 actual);
error InsufficientValue(uint256 expected, uint256 actual);
error InvalidAccount();
error InvalidAccountNonce(address account, uint256 currentNonce);
error InvalidAddress();
error InvalidAmount();
error InvalidAmount(uint256 maxAmount);
error InvalidAuthModule();
error InvalidBatchSize();
error InvalidBlockNumber(uint256 requested, uint256 current);
error InvalidCapacitorAddress();
error InvalidCapacitorType();
error InvalidChainId();
error InvalidCodeHash();
error InvalidCommand();
error InvalidCommands();
error InvalidConnection();
error InvalidContract(address target);
error InvalidContractSignature();
error InvalidCrossChainSender(address actual, address expected);
error InvalidDeliveryVaa(string reason);
error InvalidEmitter(bytes32 emitter, bytes32 registered, uint16 chainId);
error InvalidGovernance();
error InvalidImplementation();
error InvalidInitializeTransaction();
error InvalidMintLimiter();
error InvalidMsgValue();
error InvalidMsgValue(uint256 msgValue, uint256 totalFee);
error InvalidNonce();
error InvalidOperators();
error InvalidOutboxSet(address outbox);
error InvalidOverrideGasLimit();
error InvalidOverrideReceiverValue();
error InvalidOverrideRefundPerGasUnused();
error InvalidOwner();
error InvalidOwnerAddress();
error InvalidPacketId();
error InvalidPacketLength();
error InvalidPayloadId(uint8 parsed, uint8 expected);
error InvalidPayloadLength(uint256 received, uint256 expected);
error InvalidPoolId();
error InvalidProof();
error InvalidRangeBatchTimeTarget();
error InvalidRangeForceBatchTimeout();
error InvalidRangeMultiplierBatchFee();
error InvalidRole();
error InvalidRoot();
error InvalidS();
error InvalidSender();
error InvalidSetMintLimitsParams();
error InvalidShortString();
error InvalidSigLength();
error InvalidSignature();
error InvalidSignatureLength();
error InvalidSigner();
error InvalidSignerThreshold();
error InvalidSigners();
error InvalidSmtProof();
error InvalidTarget();
error InvalidThreshold();
error InvalidTimeLockHash();
error InvalidTokenAddress();
error InvalidTokenDeployer();
error InvalidTokenSet(address token);
error InvalidTransmitter();
error InvalidV();
error InvalidVaaKeyType(uint8 parsed);
error InvalidWeights();
error IsLocked();
error L1Forked();
error LengthMismatch();
error LowGasLimit();
error LowSignaturesWeight();
error MainnetSpokeConnector_finalize__DeprecatedInHubDomain();
error MainnetSpokeConnector_proposeAggregateRoot__DeprecatedInHubDomain();
error MainnetSpokeConnector_saveAggregateRoot__CallerIsNotRootManager();
error MainnetSpokeConnector_saveAggregateRoot__EmptyRoot();
error MainnetSpokeConnector_saveAggregateRoot__OnlyOptimisticMode();
error MainnetSpokeConnector_saveAggregateRoot__RootAlreadyProven();
error MalformedSigners();
error MathOverflowedMulDiv();
error MerkleLib__insert_treeIsFull();
error MerkleProofTooLong(uint256 actualLength, uint256 maxProofLength);
error MerkleTreeFull();
error MerkleTreeManager__renounceOwnership_prohibited();
error MerkleTreeManager__setArborist_alreadyArborist();
error MerkleTreeManager__setArborist_zeroAddress();
error MessageAlreadyExecuted();
error MessageFailed();
error MessageInvalid();
error MessageSendingFailed(address destination);
error MintFailed(string symbol);
error MonthlyRateGreaterThanYearlyRate(uint256, uint256);
error MsgValueNotZero();
error MsgValueTooHigh();
error MsgValueTooLow();
error MustSequenceSomeBatch();
error NativeTokenIsEther();
error NativeTransferFailed();
error NewAccInputHashDoesNotExist();
error NewPendingStateTimeoutMustBeLower();
error NewStateRootNotInsidePrime();
error NewTrustedAggregatorTimeoutMustBeLower();
error NoDeliveryInProgress();
error NoPendingPacket();
error NoPermit(bytes32 role);
error NoRootFound();
error NoSocketFee();
error NoSuchKeyset(bytes32);
error NoTicketWithID();
error NoValueInMessagesOnGasTokenNetworks();
error NotAllowedOrigin(address origin);
error NotAnEvmAddress(bytes32);
error NotApprovedByGateway();
error NotBatchPoster();
error NotCallable();
error NotContract();
error NotContract(address addr);
error NotCrossChainCall();
error NotDelayedInbox(address sender);
error NotEnoughMaticAmount();
error NotEnoughPOLAmount();
error NotExecutor();
error NotExecutorOrOwner(address actual);
error NotForked();
error NotGovernance();
error NotHub();
error NotIERC165Compliant(address guard_);
error NotInflationOwner(address);
error NotMintLimiter();
error NotOrigin();
error NotOutbox(address sender);
error NotOwner();
error NotOwner(address sender, address owner);
error NotProxy();
error NotRollup(address sender, address rollup);
error NotRollupOrOwner(address sender, address rollup, address owner);
error NotSelf();
error NotSequencerInbox(address sender);
error NotSigner();
error NotSocket();
error NotValidAmount();
error NotValidOwner();
error NotValidSignature();
error NotValidSpender();
error OldAccInputHashDoesNotExist();
error OldStateRootDoesNotExist();
error OnlyAdmin();
error OnlyAllowedContracts();
error OnlyEmergencyState();
error OnlyExecutionManager();
error OnlyNominee();
error OnlyNotEmergencyState();
error OnlyOwner();
error OnlyOwnerDestination(address expected, address actual, address destination);
error OnlyPendingAdmin();
error OnlyPolygonZkEVM();
error OnlyRollupManager();
error OnlySocket();
error OnlyTrustedAggregator();
error OnlyTrustedSequencer();
error OperatorNotAllowed(address operator);
error OwnableInvalidOwner(address owner);
error OwnableUnauthorizedAccount(address account);
error PacketLengthNotAllowed();
error PacketNotProposed();
error PathNotMinimal(uint256 index, uint256 maxIndex);
error Paused();
error PayloadTooLarge();
error PendingStateDoesNotExist();
error PendingStateInvalid();
error PendingStateNotConsolidable();
error PendingStateTimeoutExceedHaltAggregationTimeout();
error PeriodIsZero();
error PermitExpired();
error PlugDisconnected();
error PortalFacet__repayAavePortalFor_invalidAsset();
error PortalFacet__repayAavePortalFor_zeroAmount();
error PortalFacet__repayAavePortal_assetNotApproved();
error PortalFacet__repayAavePortal_insufficientFunds();
error PortalFacet__setAavePortalFee_invalidFee();
error ProofTooLong(uint256 proofLength);
error ProposedOwnableFacet__acceptProposedOwner_noOwnershipChange();
error ProposedOwnableFacet__assignRoleAdmin_invalidInput();
error ProposedOwnableFacet__assignRoleRouter_invalidInput();
error ProposedOwnableFacet__assignRoleWatcher_invalidInput();
error ProposedOwnableFacet__delayElapsed_delayNotElapsed();
error ProposedOwnableFacet__proposeAssetAllowlistRemoval_noOwnershipChange();
error ProposedOwnableFacet__proposeNewOwner_invalidProposal();
error ProposedOwnableFacet__proposeNewOwner_noOwnershipChange();
error ProposedOwnableFacet__proposeRouterAllowlistRemoval_noOwnershipChange();
error ProposedOwnableFacet__removeAssetAllowlist_noOwnershipChange();
error ProposedOwnableFacet__removeAssetAllowlist_noProposal();
error ProposedOwnableFacet__removeRouterAllowlist_noOwnershipChange();
error ProposedOwnableFacet__removeRouterAllowlist_noProposal();
error ProposedOwnableFacet__revokeRole_invalidInput();
error ProposedOwnable__onlyOwner_notOwner();
error ProposedOwnable__onlyProposed_notProposedOwner();
error ProposedOwnable__ownershipDelayElapsed_delayNotElapsed();
error ProposedOwnable__proposeNewOwner_invalidProposal();
error ProposedOwnable__proposeNewOwner_noOwnershipChange();
error ProposedOwnable__renounceOwnership_invalidProposal();
error ProposedOwnable__renounceOwnership_noProposal();
error ProxyDeniedAdminAccess();
error RateLimited__rateLimited_messageSendRateExceeded();
error RateOverLimit(uint256 newRate, uint256 currentRate);
error ReentrantDelivery(address msgSender, address lockedBy);
error RelayerFacet__addRelayer_alreadyApproved();
error RelayerFacet__removeRelayer_notApproved();
error RelayerFacet__setRelayerFeeVault_invalidRelayerFeeVault();
error RequestedGasLimitTooLow();
error RequesterNotWormholeRelayer();
error RollupAddressAlreadyExist();
error RollupMustExist();
error RollupNotChanged();
error RollupTypeDoesNotExist();
error RollupTypeObsolete();
error RootManager__renounceOwnership_prohibited();
error RootManager_activateOptimisticMode__OptimisticModeOn();
error RootManager_aggregate__OptimisticModeOn();
error RootManager_checkDomains__InvalidDomains();
error RootManager_constructor__DisputeBlocksLowerThanMin();
error RootManager_finalize__InvalidAggregateRoot();
error RootManager_finalize__InvalidInputHash();
error RootManager_finalize__ProposeInProgress();
error RootManager_onlyOptimisticMode__SlowModeOn();
error RootManager_onlyProposer__NotWhitelistedProposer(address caller);
error RootManager_propagate__AggregateRootIsZero();
error RootManager_proposeAggregateRoot__InvalidSnapshotId(uint256 snapshotId);
error RootManager_proposeAggregateRoot__ProposeInProgress();
error RootManager_sendRootToHub__NoMessageSent();
error RootManager_setDisputeBlocks__DisputeBlocksLowerThanMin();
error RootManager_setDisputeBlocks__SameDisputeBlocksAsBefore();
error RootManager_setHubDomain__InvalidDomain();
error RootManager_setMinDisputeBlocks__SameMinDisputeBlocksAsBefore();
error RoutersFacet__acceptProposedRouterOwner_badCaller();
error RoutersFacet__acceptProposedRouterOwner_notElapsed();
error RoutersFacet__addLiquidityForRouter_amountIsZero();
error RoutersFacet__addLiquidityForRouter_badRouter();
error RoutersFacet__addLiquidityForRouter_capReached();
error RoutersFacet__addLiquidityForRouter_routerEmpty();
error RoutersFacet__approveRouterForPortal_alreadyApproved();
error RoutersFacet__approveRouterForPortal_notAdded();
error RoutersFacet__approveRouter_alreadyAdded();
error RoutersFacet__approveRouter_routerEmpty();
error RoutersFacet__initializeRouter_configNotEmpty();
error RoutersFacet__onlyRouterOwner_notRouterOwner();
error RoutersFacet__proposeRouterOwner_badRouter();
error RoutersFacet__proposeRouterOwner_notNewOwner();
error RoutersFacet__removeRouterLiquidityFor_notOwner();
error RoutersFacet__removeRouterLiquidity_amountIsZero();
error RoutersFacet__removeRouterLiquidity_insufficientFunds();
error RoutersFacet__removeRouterLiquidity_recipientEmpty();
error RoutersFacet__setLiquidityFeeNumerator_tooLarge();
error RoutersFacet__setLiquidityFeeNumerator_tooSmall();
error RoutersFacet__setMaxRoutersPerTransfer_invalidMaxRoutersPerTransfer();
error RoutersFacet__setRouterOwner_noChange();
error RoutersFacet__setRouterRecipient_notNewRecipient();
error RoutersFacet__unapproveRouterForPortal_notApproved();
error RoutersFacet__unapproveRouter_notAdded();
error RoutersFacet__unapproveRouter_routerEmpty();
error SenderMustBeRollup();
error SequenceWithDataAvailabilityNotAllowed();
error SequenceZeroBatches();
error SequencedTimestampBelowForcedTimestamp();
error SequencedTimestampInvalid();
error SetupFailed();
error SignatureExpired(uint256 signatureDeadline);
error SimulationOnlyEntrypoint();
error SpokeConnector_activateOptimisticMode__OptimisticModeOn();
error SpokeConnector_constructor__DisputeBlocksLowerThanMin();
error SpokeConnector_finalize__InvalidInputHash();
error SpokeConnector_finalize__ProposeInProgress();
error SpokeConnector_finalize__ProposedHashIsFinalizedHash();
error SpokeConnector_onlyOptimisticMode__SlowModeOn();
error SpokeConnector_onlyProposer__NotAllowlistedProposer();
error SpokeConnector_proposeAggregateRoot__ProposeInProgress();
error SpokeConnector_receiveAggregateRoot__OptimisticModeOn();
error SpokeConnector_setDisputeBlocks__DisputeBlocksLowerThanMin();
error SpokeConnector_setDisputeBlocks__SameDisputeBlocksAsBefore();
error SpokeConnector_setMinDisputeBlocks__SameMinDisputeBlocksAsBefore();
error StableSwapFacet__deadlineCheck_deadlineNotMet();
error StableSwapFacet__getSwapTokenBalance_indexOutOfRange();
error StableSwapFacet__getSwapTokenIndex_notExist();
error StableSwapFacet__getSwapToken_outOfRange();
error StoredRootMustBeDifferentThanNewRoot();
error StringTooLong(string str);
error StringsInsufficientHexLength(uint256 value, uint256 length);
error SupplyExceedsMaxMonthlyCap(uint256 newSupply, uint256 maxMonthlySupply);
error SupplyExceedsMaxYearlyCap(uint256 newSupply, uint256 maxYearlySupply);
error SwapAdminFacet__disableSwap_alreadyDisabled();
error SwapAdminFacet__disableSwap_notInitialized();
error SwapAdminFacet__initializeSwap_aExceedMax();
error SwapAdminFacet__initializeSwap_adminFeeExceedMax();
error SwapAdminFacet__initializeSwap_alreadyInitialized();
error SwapAdminFacet__initializeSwap_decimalsMismatch();
error SwapAdminFacet__initializeSwap_duplicateTokens();
error SwapAdminFacet__initializeSwap_failedInitLpTokenClone();
error SwapAdminFacet__initializeSwap_feeExceedMax();
error SwapAdminFacet__initializeSwap_invalidPooledTokens();
error SwapAdminFacet__initializeSwap_tokenDecimalsExceedMax();
error SwapAdminFacet__initializeSwap_zeroTokenAddress();
error SwapAdminFacet__removeSwap_delayNotElapsed();
error SwapAdminFacet__removeSwap_notDisabledPool();
error SwapAdminFacet__removeSwap_notInitialized();
error SwapAdminFacet__updateLpTokenTarget_invalidNewAddress();
error SwitchToSameValue();
error SwitchboardExists();
error TargetChainIsNotThisChain(uint16 targetChain);
error TimeLockAlreadyScheduled();
error TimeLockNotReady();
error TokenAlreadyExists(string symbol);
error TokenContractDoesNotExist(address token);
error TokenDeployFailed(string symbol);
error TokenDoesNotExist(string symbol);
error TokenFacet__addAssetId_alreadyAdded();
error TokenFacet__addAssetId_badBurn();
error TokenFacet__addAssetId_badMint();
error TokenFacet__enrollAdoptedAndLocalAssets_emptyCanonical();
error TokenFacet__removeAssetId_invalidParams();
error TokenFacet__removeAssetId_notAdded();
error TokenFacet__removeAssetId_remainsCustodied();
error TokenFacet__setLiquidityCap_notCanonicalDomain();
error TokenFacet__setupAssetWithDeployedRepresentation_invalidRepresentation();
error TokenFacet__setupAssetWithDeployedRepresentation_onCanonicalDomain();
error TokenFacet__setupAsset_invalidCanonicalConfiguration();
error TokenFacet__setupAsset_representationListed();
error TokenFacet__updateDetails_localNotFound();
error TokenFacet__updateDetails_notApproved();
error TokenFacet__updateDetails_onlyRemote();
error TokenNotSupported();
error TokenTransferFailed();
error TotalLimitIsZero(address token);
error TransactionsLengthAboveMax();
error TrustedAggregatorTimeoutExceedHaltAggregationTimeout();
error TrustedAggregatorTimeoutNotExpired();
error TypedMemView__assertType_typeAssertionFailed(uint256 actual, uint256 expected);
error TypedMemView__assertValid_validityAssertionFailed();
error TypedMemView__index_indexMoreThan32Bytes();
error TypedMemView__index_overrun(uint256 loc, uint256 len, uint256 index, uint256 slice);
error TypedMemView__unsafeCopyTo_identityOOG();
error TypedMemView__unsafeCopyTo_invalidPointer();
error TypedMemView__unsafeCopyTo_nullPointer();
error UnequalArrayLengths();
error UnknownRoot(bytes32 root);
error UpdateNotCompatible();
error UpdateToSameRollupTypeID();
error VaaKeysDoNotMatchVaas(uint8 index);
error VaaKeysLengthDoesNotMatchVaasLength(uint256 keys, uint256 vaas);
error ValueSentTooLow();
error ValueShouldBeGreaterThanFee();
error VerificationFailed();
error WatcherFound();
error WatcherNotFound();
error WhitelistingDisabled();
error WithdrawEthFail(address destination);
error ZeroAddress();
error ZeroAmount();

type MemoryPointer is uint256;
type ShortString is bytes32;
type TUint256Slot is bytes32;
type Fixed18 is int256;
type Price is uint128;
type Quantity is uint128;
type UFixed is uint256;
type Id is uint8;

IMulticall3 constant multicall = IMulticall3(0xcA11bde05977b3631167028862bE2a173976CA11);
KromaPortal constant portal = KromaPortal(payable ((0x713C2BEd44eB45D490afB8D4d1aA6F12290B829a)));
Vm constant vm = Vm(VM_ADDRESS);
Vm constant vm = Vm((uint160(uint256(keccak256("hevm cheat code")))));
VmSafe constant vmSafe = VmSafe(VM_ADDRESS);
VmSafe constant vm = VmSafe((uint160(uint256(keccak256("hevm cheat code")))));
ZkBridgeLike constant zkErc20Bridge = ZkBridgeLike(0x57891966931Eb4Bb6FB81430E6cE0A03AAbDe063);
ZkSyncInterface constant zkSync = ZkSyncInterface(0x32400084C286CF3E17e7B677ea9583e60a000324);
ZkSyncInterface constant zkSyncEthBridge = ZkSyncInterface(0x32400084C286CF3E17e7B677ea9583e60a000324);
ZkSyncInterface constant zkSyncMessageBridge = ZkSyncInterface(0x32400084C286CF3E17e7B677ea9583e60a000324);
address constant BASE_FEE_VAULT = 0x4200000000000000000000000000000000000019;
address constant CONSOLE = 0x000000000000000000636F6e736F6c652e6c6f67;
address constant CREATE2_FACTORY = 0x4e59b44847b379578588920cA78FbF26c0B4956C;
address constant Create2Deployer = 0x13b0D85CcB8bf860b6b79AF3029fCA081AE9beF2;
address constant DEFAULT_L2_SENDER = 0x000000000000000000000000000000000000dEaD;
address constant DEFAULT_TEST_CONTRACT = 0x5615dEB798BB3E4dFa0139dFa1b3D433Cc23b72f;
address constant DEPLOYER_WHITELIST = 0x4200000000000000000000000000000000000002;
address constant DROP_XDOMAIN_MESSAGE_SENDER = 0x6f297C61B5C92eF107fFD30CD56AFFE5A273e841;
address constant DeterministicDeploymentProxy = 0x4e59b44847b379578588920cA78FbF26c0B4956C;
address constant EAS = 0x4200000000000000000000000000000000000021;
address constant EMPTY_ACTIVEOUTBOX = (type(uint160).max);
address constant EntryPoint = 0x5FF137D4b0FDCD49DcA30c7CF57E578a026d2789;
address constant GAS_PRICE_ORACLE = 0x420000000000000000000000000000000000000F;
address constant GOVERNANCE_TOKEN = 0x4200000000000000000000000000000000000042;
address constant L1_BLOCK_ATTRIBUTES = 0x4200000000000000000000000000000000000015;
address constant L1_BLOCK_NUMBER = 0x4200000000000000000000000000000000000013;
address constant L1_FEE_VAULT = 0x420000000000000000000000000000000000001A;
address constant L1_MESSAGE_SENDER = 0x4200000000000000000000000000000000000001;
address constant L2_CROSS_DOMAIN_MESSENGER = 0x4200000000000000000000000000000000000007;
address constant L2_ERC721_BRIDGE = 0x4200000000000000000000000000000000000014;
address constant L2_STANDARD_BRIDGE = 0x4200000000000000000000000000000000000010;
address constant L2_TO_L1_MESSAGE_PASSER = 0x4200000000000000000000000000000000000016;
address constant LEGACY_ERC20_ETH = 0xDeadDeAddeAddEAddeadDEaDDEAdDeaDDeAD0000;
address constant LEGACY_MESSAGE_PASSER = 0x4200000000000000000000000000000000000000;
address constant MULTICALL3_ADDRESS = 0xcA11bde05977b3631167028862bE2a173976CA11;
address constant MultiCall3 = 0xcA11bde05977b3631167028862bE2a173976CA11;
address constant MultiSendCallOnly_v130 = 0xA1dabEF33b3B82c7814B6D82A79e50F4AC44102B;
address constant MultiSend_v130 = 0x998739BFdAAdde7C933B942a68053933098f9EDa;
address constant OPTIMISM_MINTABLE_ERC20_FACTORY = 0x4200000000000000000000000000000000000012;
address constant OPTIMISM_MINTABLE_ERC721_FACTORY = 0x4200000000000000000000000000000000000017;
address constant PROXY_ADMIN = 0x4200000000000000000000000000000000000018;
address constant Permit2 = 0x000000000022D473030F116dDEE9F6B43aC78BA3;
address constant SCHEMA_REGISTRY = 0x4200000000000000000000000000000000000020;
address constant SEQUENCER_FEE_WALLET = 0x4200000000000000000000000000000000000011;
address constant SafeL2_v130 = 0xfb1bffC9d739B8D520DaF37dF666da4C687191EA;
address constant SafeSingletonFactory = 0x914d7Fec6aaC8cd542e72Bca78B30650d45643d7;
address constant Safe_v130 = 0x69f4D1788e39c87893C980c06EdF4b7f686e2938;
address constant SenderCreator = 0x7fc98430eAEdbb6070B35B39D798725049088348;
address constant WETH9 = 0x4200000000000000000000000000000000000006;
address constant CONSOLE2_ADDRESS = 0x000000000000000000636F6e736F6c652e6c6f67;
address constant CREATE2_FACTORY = 0x4e59b44847b379578588920cA78FbF26c0B4956C;
address constant DAO_V1_TREASURY = 0xDd92eb1478D3189707aB7F4a5aCE3a615cdD0476;
address constant DAO_V1_VOTING_CONTRACT = 0x2211bFD97b1c02aE8Ac305d206e9780ba7D8BfF4;
address constant EMPTY_ACTIVEOUTBOX = (type(uint160).max);
address constant SENDER_DEFAULT_CONTEXT = (type(uint160).max);
address constant ETHPNT_TOKEN_ADDRESS = 0xf4eA6B892853413bD9d9f1a5D3a620A0ba39c5b2;
address constant PNT_TOKEN_ADDRESS = 0x89Ab32156e46F46D02ade3FEcbe5Fc4243B9AAeD;
address constant RETRYABLE_TICKET_MAGIC = 0xa723C008e76E379c55599D2E4d93879BeaFDa79C;
address constant l2RefundL2Address = 0x428AB2BA90Eba0a4Be7aF34C9Ac451ab061AC010;
bytes constant ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
bytes constant sha256MultiHash = hex"1220";
bytes constant EXPLANATION_KEY = "explanation";
bytes constant INITIALIZE_TX_BRIDGE_PARAMS = hex"80808401c9c38094";
bytes constant PROPOSAL_HASH_KEY = "proposalHash";
bytes constant RULES_KEY = "rules";
bytes constant arithmeticError = abi.encodeWithSignature("Panic(uint256)", 0x11);
bytes constant assertionError = abi.encodeWithSignature("Panic(uint256)", 0x01);
bytes constant divisionError = abi.encodeWithSignature("Panic(uint256)", 0x12);
bytes constant encodeStorageError = abi.encodeWithSignature("Panic(uint256)", 0x22);
bytes constant enumConversionError = abi.encodeWithSignature("Panic(uint256)", 0x21);
bytes constant indexOOBError = abi.encodeWithSignature("Panic(uint256)", 0x32);
bytes constant memOverflowError = abi.encodeWithSignature("Panic(uint256)", 0x41);
bytes constant popError = abi.encodeWithSignature("Panic(uint256)", 0x31);
bytes constant zeroVarError = abi.encodeWithSignature("Panic(uint256)", 0x51);
bytes1 constant MSG_ROOT = 0;
bytes1 constant DATA_AUTHENTICATED_FLAG = 0x40;
bytes1 constant INITIALIZE_TX_EFFECTIVE_PERCENTAGE = 0xFF;
bytes13 constant DEPLOY_CODE_PREFIX = 0x600D380380600D6000396000f3;
bytes13 constant DEPLOY_CODE_PREFIX = 0x600D380380600D6000396000f3;
bytes15 constant SUFFIX = hex"5af43d82803e903d91602b57fd5bf3";
bytes16 constant HEX_DIGITS = "0123456789abcdef";
bytes16 constant _HEX_SYMBOLS = "0123456789abcdef";
bytes16 constant _SYMBOLS = "0123456789abcdef";
bytes20 constant PREFIX = hex"3d602d80600a3d3981f3363d3d373d3d3d363d73";
bytes32 constant CREATE2_PREFIX = keccak256("zksyncCreate2");
bytes32 constant DIAMOND_STORAGE_POSITION = 0xc8fcad8db84d3cc18b4c41d551ea0ee66dd599cde068d998e57d5e09332c131b; // keccak256("diamond.standard.diamond.storage") - 1;
bytes32 constant DIAMOND_STORAGE_POSITION = keccak256("diamond.standard.diamond.storage");
bytes32 constant UPPER_BIT_MASK = (0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff);
bytes32 constant IMPLEMENTATION_KEY = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
bytes32 constant OWNER_KEY = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant Erc777Token_INTERFACE_HASH = keccak256("ERC777Token");
bytes32 constant TOKENS_RECIPIENT_INTERFACE_HASH = keccak256("ERC777TokensRecipient");
bytes32 constant ADMIN_SLOT = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant APP_ID_POSITION = 0xd625496217aa6a3453eecb9c3489dc5a53e6c67b444329ea2b2cbc9ff547639b;
bytes32 constant APP_ID_POSITION = keccak256("aragonOS.appStorage.appId");
bytes32 constant BEACON_SLOT = 0xa3f0ad74e5423aebfd80d3ef4346578335a9a72aeaee59ff6cb3582b35133d50;
bytes32 constant DEPOSITABLE_POSITION = 0x665fd576fbbe6f247aff98f5c94a561e3f71ec2d3c988d56f12d342396c50cea;
bytes32 constant EVMSCRIPT_REGISTRY_APP_ID = 0xddbcfd564f642ab5627cf68b9b7d374fb4f8a36e941a75d89c87998cef03bd61;
bytes32 constant EVMSCRIPT_REGISTRY_APP_ID = apmNamehash("evmreg");
bytes32 constant EXECUTOR_TYPE = 0x2dc858a00f3e417be1394b87c07158e989ec681ce8cc68a9093680ac1a870302;
bytes32 constant EXECUTOR_TYPE = keccak256("CALLS_SCRIPT");
bytes32 constant FALLBACK_HANDLER_STORAGE_SLOT = 0x6c9a6c4a39284e37ed1cf53d337577d14212a4870fb976a4366c693b939918d5;
bytes32 constant GUARD_STORAGE_SLOT = 0x4a204f620c8c5ccdca3fd54d003badd85ba500436a431f0cbda4f558c93c34c8;
bytes32 constant IMPLEMENTATION_SLOT = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
bytes32 constant INITIALIZATION_BLOCK_POSITION = 0xebb05b386a8d34882b8711d156f463690983dc47815980fb82aeeff1aa43579e;
bytes32 constant KERNEL_APP_ADDR_NAMESPACE = 0xd6f028ca0e8edb4a8c9757ca4fdccab25fa1e0317da1188108f7d2dee14902fb;
bytes32 constant KERNEL_APP_ADDR_NAMESPACE = keccak256("app");
bytes32 constant KERNEL_APP_BASES_NAMESPACE = 0xf1f3eb40f5bc1ad1344716ced8b8a0431d840b5783aea1fd01786bc26f35ac0f;
bytes32 constant KERNEL_APP_BASES_NAMESPACE = keccak256("base");
bytes32 constant KERNEL_CORE_APP_ID = 0x3b4bf6bf3ad5000ecf0f989d5befde585c6860fea3e574a4fab4c49d1c177d9c;
bytes32 constant KERNEL_CORE_APP_ID = apmNamehash("kernel");
bytes32 constant KERNEL_CORE_NAMESPACE = 0xc681a85306374a5ab27f0bbc385296a54bcd314a1948b6cf61c4ea1bc44bb9f8;
bytes32 constant KERNEL_CORE_NAMESPACE = keccak256("core");
bytes32 constant KERNEL_DEFAULT_ACL_APP_ID = 0xe3262375f45a6e2026b7e7b18c2b807434f2508fe1a2a3dfb493c7df8f4aad6a;
bytes32 constant KERNEL_DEFAULT_ACL_APP_ID = apmNamehash("acl");
bytes32 constant KERNEL_DEFAULT_VAULT_APP_ID = 0x7e852e0fcfce6551c13800f1e7476f982525c2b5277ba14b24339c68416336d1;
bytes32 constant KERNEL_DEFAULT_VAULT_APP_ID = apmNamehash("vault");
bytes32 constant KERNEL_POSITION = 0x4172f0f7d2289153072b0a6ca36959e0cbe2efc3afe50fc81636caa96338137b;
bytes32 constant KERNEL_POSITION = keccak256("aragonOS.appStorage.kernel");
bytes32 constant KEY_ADMIN_EPOCH = keccak256('admin-epoch');
bytes32 constant KEY_ALL_TOKENS_FROZEN = keccak256('all-tokens-frozen');
bytes32 constant KEY_GOVERNANCE = bytes32(0xabea6fd3db56a6e6d0242111b43ebb13d1c42709651c032c7894962023a1f909);
bytes32 constant KEY_IMPLEMENTATION = bytes32(0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc);
bytes32 constant KEY_MINT_LIMITER = bytes32(0x627f0c11732837b3240a2de89c0b6343512886dd50978b99c76a68c6416a4d92);
bytes32 constant KEY_OPERATOR_EPOCH = keccak256('operator-epoch');
bytes32 constant KEY_OWNER_EPOCH = keccak256('owner-epoch');
bytes32 constant PINNED_CODE_POSITION = 0xdee64df20d65e53d7f51cb6ab6d921a0a6a638a91e942e1d8d02df28e31c038e;
bytes32 constant PREFIX_ADMIN = keccak256('admin');
bytes32 constant PREFIX_ADMIN_COUNT = keccak256('admin-count');
bytes32 constant PREFIX_ADMIN_THRESHOLD = keccak256('admin-threshold');
bytes32 constant PREFIX_ADMIN_VOTED = keccak256('admin-voted');
bytes32 constant PREFIX_ADMIN_VOTE_COUNTS = keccak256('admin-vote-counts');
bytes32 constant PREFIX_COMMAND_EXECUTED = keccak256('command-executed');
bytes32 constant PREFIX_CONTRACT_CALL_APPROVED = keccak256('contract-call-approved');
bytes32 constant PREFIX_CONTRACT_CALL_APPROVED_WITH_MINT = keccak256('contract-call-approved-with-mint');
bytes32 constant PREFIX_IS_ADMIN = keccak256('is-admin');
bytes32 constant PREFIX_IS_OPERATOR = keccak256('is-operator');
bytes32 constant PREFIX_IS_OWNER = keccak256('is-owner');
bytes32 constant PREFIX_OPERATOR = keccak256('operator');
bytes32 constant PREFIX_OPERATOR_COUNT = keccak256('operator-count');
bytes32 constant PREFIX_OPERATOR_THRESHOLD = keccak256('operator-threshold');
bytes32 constant PREFIX_OWNER = keccak256('owner');
bytes32 constant PREFIX_OWNER_COUNT = keccak256('owner-count');
bytes32 constant PREFIX_OWNER_THRESHOLD = keccak256('owner-threshold');
bytes32 constant PREFIX_TIME_LOCK = keccak256('time-lock');
bytes32 constant PREFIX_TOKEN_ADDRESS = keccak256('token-address');
bytes32 constant PREFIX_TOKEN_FROZEN = keccak256('token-frozen');
bytes32 constant PREFIX_TOKEN_MINT_AMOUNT = keccak256('token-mint-amount');
bytes32 constant PREFIX_TOKEN_MINT_LIMIT = keccak256('token-mint-limit');
bytes32 constant PREFIX_TOKEN_TYPE = keccak256('token-type');
bytes32 constant PROXY_OWNER_ADDRESS = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant REENTRANCY_MUTEX_POSITION = keccak256("aragonOS.reentrancyGuard.mutex");
bytes32 constant SELECTOR_APPROVE_CONTRACT_CALL = keccak256('approveContractCall');
bytes32 constant SELECTOR_APPROVE_CONTRACT_CALL_WITH_MINT = keccak256('approveContractCallWithMint');
bytes32 constant SELECTOR_BURN_TOKEN = keccak256('burnToken');
bytes32 constant SELECTOR_DEPLOY_TOKEN = keccak256('deployToken');
bytes32 constant SELECTOR_MINT_TOKEN = keccak256('mintToken');
bytes32 constant SELECTOR_TRANSFER_OPERATORSHIP = keccak256('transferOperatorship');
bytes32 constant SELECTOR_TRANSFER_OWNERSHIP = keccak256('transferOwnership');
bytes32 constant _ADMIN_SLOT = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant _BEACON_SLOT = 0xa3f0ad74e5423aebfd80d3ef4346578335a9a72aeaee59ff6cb3582b35133d50;
bytes32 constant _IMPLEMENTATION_SLOT = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
bytes32 constant _OWNER_SLOT = 0x02016836a56b71f0d02689e69e326f4f4c1b9057164ef592671cf0d37c8040c0;
bytes32 constant _SET_FEE_ROLE = keccak256("SET_FEE_ROLE");
bytes32 constant CHILD_CHAIN = keccak256("childChain");
bytes32 constant CREATE2_PREFIX = keccak256("zksyncCreate2");
bytes32 constant DEPOSIT_MANAGER = keccak256("depositManager");
bytes32 constant DOMAIN_SEPARATOR_TYPEHASH = 0x47e79534a245952e8b16893a336b85a3d9ea9fa8c573f3d803afb92a79469218;
bytes32 constant DOMAIN_TYPE_SIGNATURE_HASH = bytes32(0x8b73c3c69bb8fe3d512ecc4cf759cc79239f7b179b0ffacaa9a75d522b39400f);
bytes32 constant EMPTY_STRING_KECCAK = 0xc5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470;
bytes32 constant FALLBACK_SENTINEL = 0x00000000000000000000000000000000000000000000000000000000000000FF;
bytes32 constant KEY_ALL_TOKENS_FROZEN = keccak256('all-tokens-frozen');
bytes32 constant OUTPUTID_DEFAULT_CONTEXT = bytes32(type(uint256).max);
bytes32 constant PERMIT_SIGNATURE_HASH = bytes32(0x6e71edae12b1b97f4d1f60370fef10105fa2faae0126114a169c64845d6126c9);
bytes32 constant PREFIX_TOKEN_FROZEN = keccak256('token-frozen');
bytes32 constant REENTRANCY_MUTEX_POSITION = 0xe855346402235fdd185c890e68d2c4ecad599b88587635ee285bce2fda58dacb;
bytes32 constant SAFE_TX_TYPEHASH = 0xbb8310d486368db6bd6f849402fdd73ad53d316b5a4b2644ad6efe0f941286d8;
bytes32 constant SLASHING_MANAGER = keccak256("slashingManager");
bytes32 constant STAKE_MANAGER = keccak256("stakeManager");
bytes32 constant STATE_SENDER = keccak256("stateSender");
bytes32 constant VALIDATOR_SHARE = keccak256("validatorShare");
bytes32 constant WETH_TOKEN = keccak256("wethToken");
bytes32 constant WITHDRAW_MANAGER = keccak256("withdrawManager");
bytes32 constant _ADMIN_SLOT = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant _BEACON_SLOT = 0xa3f0ad74e5423aebfd80d3ef4346578335a9a72aeaee59ff6cb3582b35133d50;
bytes32 constant _HASHED_NAME = keccak256("Permit2");
bytes32 constant _IMPLEMENTATION_SLOT = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
bytes32 constant _ROLLBACK_SLOT = 0x4910fdfa16fed3260ed0e7147f7cc6da11a60208b5b9406d12a635614ffd9143;
bytes32 constant _TYPE_HASH = keccak256("EIP712Domain(string name,string version,uint256 chainId)");
bytes32 constant _TYPE_HASH = keccak256("EIP712Domain(string name,string version,uint256 chainId,address verifyingContract)");
bytes32 constant masterPosition = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant targetPosition = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
bytes32 constant ADMIN_ROLE = keccak256("ADMIN_ROLE");
bytes32 constant APP_MANAGER_ROLE = 0xb6d92708f3d4817afc106147d969e229ced5c46e65e0a5002a0d391287762bd0;
bytes32 constant APP_MANAGER_ROLE = keccak256("APP_MANAGER_ROLE");
bytes32 constant Bridge = "Bridge";
bytes32 constant CANCELLER_ROLE = keccak256("CANCELLER_ROLE");
bytes32 constant CREATE_PERMISSIONS_ROLE = 0x0b719b33c83b8e5d300c521cb8b54ae9bd933996a14bef8c2f4e0285d2d2400a;
bytes32 constant CREATE_PERMISSIONS_ROLE = keccak256("CREATE_PERMISSIONS_ROLE");
bytes32 constant CREATE_VOTES_ROLE = keccak256("CREATE_VOTES_ROLE");
bytes32 constant ChildMessenger = "ChildMessenger";
bytes32 constant CollateralWhitelist = "CollateralWhitelist";
bytes32 constant DEFAULT_ADMIN_ROLE = 0x00;
bytes32 constant EMPTY_PARAM_HASH = 0x290decd9548b62a8d60345a988386fc84ba6bc95484008f6362f93160ef3e563;
bytes32 constant EMPTY_PARAM_HASH = keccak256(uint256(0));
bytes32 constant EXECUTOR_ROLE = keccak256("EXECUTOR_ROLE");
bytes32 constant FinancialContractsAdmin = "FinancialContractsAdmin";
bytes32 constant GUARDIAN_SLOT = bytes32(uint256(keccak256("superchainConfig.guardian")) - 1);
bytes32 constant GenericHandler = "GenericHandler";
bytes32 constant IdentifierWhitelist = "IdentifierWhitelist";
bytes32 constant MINTER_ROLE = keccak256("MINTER_ROLE");
bytes32 constant MODIFY_BUFFER_BLOCKS_ROLE = keccak256("MODIFY_BUFFER_BLOCKS_ROLE");
bytes32 constant MODIFY_EXECUTION_DELAY_ROLE = keccak256("MODIFY_EXECUTION_DELAY_ROLE");
bytes32 constant MODIFY_MIN_OPEN_VOTE_AMOUNT_ROLE = keccak256("MODIFY_MIN_OPEN_VOTE_AMOUNT_ROLE");
bytes32 constant MODIFY_QUORUM_ROLE = keccak256("MODIFY_QUORUM_ROLE");
bytes32 constant MODIFY_SUPPORT_ROLE = keccak256("MODIFY_SUPPORT_ROLE");
bytes32 constant NO_PERMISSION = bytes32(0);
bytes32 constant OP_ADD = keccak256("OP_ADD");
bytes32 constant OP_SUB = keccak256("OP_SUB");
bytes32 constant OptimisticOracle = "OptimisticOracle";
bytes32 constant OptimisticOracleV2 = "OptimisticOracleV2";
bytes32 constant OptimisticOracleV3 = "OptimisticOracleV3";
bytes32 constant Oracle = "Oracle";
bytes32 constant OracleHub = "OracleHub";
bytes32 constant OracleSpoke = "OracleSpoke";
bytes32 constant PAUSED_SLOT = bytes32(uint256(keccak256("superchainConfig.paused")) - 1);
bytes32 constant PROPOSER_ROLE = keccak256("PROPOSER_ROLE");
bytes32 constant REGISTRY_ADD_EXECUTOR_ROLE = 0xc4e90f38eea8c4212a009ca7b8947943ba4d4a58d19b683417f65291d1cd9ed2;
bytes32 constant REGISTRY_ADD_EXECUTOR_ROLE = keccak256("REGISTRY_ADD_EXECUTOR_ROLE");
bytes32 constant REGISTRY_MANAGER_ROLE = 0xf7a450ef335e1892cb42c8ca72e7242359d7711924b75db5717410da3f614aa3;
bytes32 constant REGISTRY_MANAGER_ROLE = keccak256("REGISTRY_MANAGER_ROLE");
bytes32 constant ROLE_GIRAFFE = keccak256("ROLE_GIRAFFE");
bytes32 constant ROLE_HIPPO = keccak256("ROLE_HIPPO");
bytes32 constant Registry = "Registry";
bytes32 constant SEND_MESSAGE_EVENT_SIG = 0x8c5261668696ce22758910d05bab8f186d6eb247ceac2af2e82c7dc17669b036;
bytes32 constant SkinnyOptimisticOracle = "SkinnyOptimisticOracle";
bytes32 constant Store = "Store";
bytes32 constant TIMELOCK_ADMIN_ROLE = keccak256("TIMELOCK_ADMIN_ROLE");
bytes32 constant UNSAFE_BLOCK_SIGNER_SLOT = keccak256("systemconfig.unsafeblocksigner");
bytes32 constant _PING = keccak256("PING");
bytes32 constant _PONG = keccak256("PONG");
bytes32 constant _TOKEN_PERMISSIONS_TYPEHASH = keccak256("TokenPermissions(address token,uint256 amount)");
bytes32 constant defaultIdentifier = "ASSERT_TRUTH";
bytes4 constant EIP1271_MAGIC_VALUE = 0x20c13b0b;
bytes4 constant ERC20_SELECTOR = bytes4(keccak256("ERC20Token(address)"));
bytes4 constant ERC721_SELECTOR = bytes4(keccak256("ERC721Token(address,uint256)"));
bytes4 constant ETH_SELECTOR = bytes4(keccak256("ETH()"));
bytes4 constant TRANSFER_SELECTOR = 0xa9059cbb;
bytes4 constant _ERC721_RECEIVED = 0x150b7a02;
bytes4 constant _INTERFACE_ID_ERC165 = 0x01ffc9a7;
bytes4 constant _INTERFACE_ID_ERC721 = 0x80ac58cd;
bytes4 constant _INTERFACE_ID_ERC721_ENUMERABLE = 0x780e9d63;
bytes4 constant _INTERFACE_ID_ERC721_METADATA = 0x5b5e139f;
bytes4 constant _INTERFACE_ID_INVALID = 0xffffffff;
bytes4 constant _PERMIT_SIGNATURE = 0xd505accf;
bytes4 constant _PERMIT_SIGNATURE_DAI = 0x8fcbaf0c;
int256 constant _INT256_MIN = --2**255;
int256 constant INT256_MIN = --57896044618658097711785492504343953926634992332820282019728792003956564819968;
int256 constant _INT256_MIN = ++2**255;
int256 constant INT256_MIN = --57896044618658097711785492504343953926634992332820282019728792003956564819968;

int256 constant _INT256_MIN = -2**255;
int256 constant INT256_MIN = -57896044618658097711785492504343953926634992332820282019728792003956564819968;
int256 constant _INT256_MIN = ~2**255;
int256 constant INT256_MIN = ~57896044618658097711785492504343953926634992332820282019728792003956564819968;
int256 constant _INT256_MIN = !2**255;
int256 constant INT256_MIN = !57896044618658097711785492504343953926634992332820282019728792003956564819968;
int256 constant SFP_SCALING_FACTOR = 10**18;
// string constant BLUE = "\u001b[94m";
// string constant BOLD = "\u001b[1m";
// string constant CYAN = "\u001b[96m";
// string constant DIM = "\u001b[2m";
string constant GOVERNANCE_TAG = "STARKWARE_DEFAULT_GOVERNANCE_INFO";
// string constant GREEN = "\u001b[92m";
// string constant INVERSE = "\u001b[7m";
// string constant ITALIC = "\u001b[3m";
string constant L1L2_MESSAGE_MAP_TAG = "STARKNET_1.0_MSGING_L1TOL2_MAPPPING_V2";
string constant L1L2_MESSAGE_NONCE_TAG = "STARKNET_1.0_MSGING_L1TOL2_NONCE";
string constant L2L1_MESSAGE_MAP_TAG = "STARKNET_1.0_MSGING_L2TOL1_MAPPPING";
// string constant MAGENTA = "\u001b[95m";
string constant OPERATORS_MAPPING_TAG = "STARKNET_1.0_ROLES_OPERATORS_MAPPING_TAG";
// string constant RED = "\u001b[91m";
// string constant RESET = "\u001b[0m";
string constant STARKNET_GOVERNANCE_INFO_TAG = "STARKNET_1.0_GOVERNANCE_INFO";
string constant STORAGE_TAG = "STARKWARE_CONTRACTS_GOVERENED_FINALIZABLE_1.0_TAG";
// string constant UNDERLINE = "\u001b[4m";
// string constant YELLOW = "\u001b[93m";
string constant BRIDGED_TOKEN_TAG = "STARKNET_ERC20_TOKEN_BRIDGE_TOKEN_ADDRESS";
string constant BRIDGE_IS_ACTIVE_TAG = "STARKNET_TOKEN_BRIDGE_IS_ACTIVE";
string constant CONFIG_HASH_TAG = "STARKNET_1.0_STARKNET_CONFIG_HASH";
string constant DEPOSITOR_ADDRESSES_TAG = "STARKNET_TOKEN_BRIDGE_DEPOSITOR_ADDRESSES";
string constant L2_TOKEN_TAG = "STARKNET_TOKEN_BRIDGE_L2_TOKEN_CONTRACT";
string constant MAX_DEPOSIT_TAG = "STARKNET_TOKEN_BRIDGE_MAX_DEPOSIT";
string constant MAX_TOTAL_BALANCE_TAG = "STARKNET_TOKEN_BRIDGE_MAX_TOTAL_BALANCE";
string constant MESSAGING_CONTRACT_TAG = "STARKNET_TOKEN_BRIDGE_MESSAGING_CONTRACT";
string constant MINTABLE_PREFIX = "MINTABLE:";
string constant NFT_ASSET_ID_PREFIX = "NFT:";
string constant PROGRAM_HASH_TAG = "STARKNET_1.0_INIT_PROGRAM_HASH_UINT";
string constant STATE_STRUCT_TAG = "STARKNET_1.0_INIT_STARKNET_STATE_STRUCT";
string constant VERIFIER_ADDRESS_TAG = "STARKNET_1.0_INIT_VERIFIER_ADDRESS";
string constant name = "ZkSync";
string constant version = "1.0";
// string constant EIP191_PREFIX_FOR_EIP712_STRUCTURED_DATA = '\x19\x01';
string constant ERROR_ADD_OVERFLOW = "MATH64_ADD_OVERFLOW";
string constant ERROR_ADD_OVERFLOW = "MATH_ADD_OVERFLOW";
string constant ERROR_ALREADY_INITIALIZED = "INIT_ALREADY_INITIALIZED";
string constant ERROR_APP_NOT_CONTRACT = "KERNEL_APP_NOT_CONTRACT";
string constant ERROR_AUTH_FAILED = "APP_AUTH_FAILED";
string constant ERROR_AUTH_FAILED = "KERNEL_AUTH_FAILED";
string constant ERROR_AUTH_INIT_KERNEL = "ACL_AUTH_INIT_KERNEL";
string constant ERROR_AUTH_NO_MANAGER = "ACL_AUTH_NO_MANAGER";
string constant ERROR_BLACKLISTED_CALL = "EVMCALLS_BLACKLISTED_CALL";
string constant ERROR_CALL_REVERTED = "EVMCALLS_CALL_REVERTED";
string constant ERROR_CAN_NOT_EXECUTE = "DANDELION_VOTING_CAN_NOT_EXECUTE";
string constant ERROR_CAN_NOT_FORWARD = "DANDELION_VOTING_CAN_NOT_FORWARD";
string constant ERROR_CAN_NOT_OPEN_VOTE = "DANDELION_VOTING_CAN_NOT_OPEN_VOTE";
string constant ERROR_CAN_NOT_VOTE = "DANDELION_VOTING_CAN_NOT_VOTE";
string constant ERROR_CHANGE_QUORUM_PCTS = "DANDELION_VOTING_CHANGE_QUORUM_PCTS";
string constant ERROR_CHANGE_SUPPORT_PCTS = "DANDELION_VOTING_CHANGE_SUPPORT_PCTS";
string constant ERROR_CHANGE_SUPPORT_TOO_BIG = "DANDELION_VOTING_CHANGE_SUPP_TOO_BIG";
string constant ERROR_DISALLOWED = "RECOVER_DISALLOWED";
string constant ERROR_DIV_ZERO = "MATH64_DIV_ZERO";
string constant ERROR_DIV_ZERO = "MATH_DIV_ZERO";
string constant ERROR_EXECUTOR_DISABLED = "EVMREG_EXECUTOR_DISABLED";
string constant ERROR_EXECUTOR_ENABLED = "EVMREG_EXECUTOR_ENABLED";
string constant ERROR_EXECUTOR_INVALID_RETURN = "EVMRUN_EXECUTOR_INVALID_RETURN";
string constant ERROR_EXECUTOR_UNAVAILABLE = "EVMRUN_EXECUTOR_UNAVAILABLE";
string constant ERROR_EXISTENT_MANAGER = "ACL_EXISTENT_MANAGER";
string constant ERROR_IMPROPER_LENGTH = "CONVERSION_IMPROPER_LENGTH";
string constant ERROR_INEXISTENT_EXECUTOR = "EVMREG_INEXISTENT_EXECUTOR";
string constant ERROR_INIT_PCTS = "DANDELION_VOTING_INIT_PCTS";
string constant ERROR_INIT_SUPPORT_TOO_BIG = "DANDELION_VOTING_INIT_SUPPORT_TOO_BIG";
string constant ERROR_INVALID_APP_CHANGE = "KERNEL_INVALID_APP_CHANGE";
string constant ERROR_INVALID_LENGTH = "EVMCALLS_INVALID_LENGTH";
string constant ERROR_MUL_OVERFLOW = "MATH64_MUL_OVERFLOW";
string constant ERROR_MUL_OVERFLOW = "MATH_MUL_OVERFLOW";
string constant ERROR_NOT_INITIALIZED = "INIT_NOT_INITIALIZED";
string constant ERROR_NO_VOTE = "DANDELION_VOTING_NO_VOTE";
string constant ERROR_NUMBER_TOO_BIG = "UINT64_NUMBER_TOO_BIG";
string constant ERROR_ORACLE_SENDER_MISSING = "DANDELION_VOTING_ORACLE_SENDER_MISSING";
string constant ERROR_ORACLE_SENDER_TOO_BIG = "DANDELION_VOTING_ORACLE_SENDER_TOO_BIG";
string constant ERROR_ORACLE_SENDER_ZERO = "DANDELION_VOTING_ORACLE_SENDER_ZERO";
string constant ERROR_PROTECTED_STATE_MODIFIED = "EVMRUN_PROTECTED_STATE_MODIFIED";
string constant ERROR_REENTRANT = "REENTRANCY_REENTRANT_CALL";
string constant ERROR_SCRIPT_LENGTH_TOO_SHORT = "EVMREG_SCRIPT_LENGTH_TOO_SHORT";
string constant ERROR_SUB_UNDERFLOW = "MATH64_SUB_UNDERFLOW";
string constant ERROR_SUB_UNDERFLOW = "MATH_SUB_UNDERFLOW";
string constant ERROR_TOKEN_ALLOWANCE_REVERTED = "SAFE_ERC_20_ALLOWANCE_REVERTED";
string constant ERROR_TOKEN_BALANCE_REVERTED = "SAFE_ERC_20_BALANCE_REVERTED";
string constant ERROR_TOKEN_TRANSFER_FAILED = "RECOVER_TOKEN_TRANSFER_FAILED";
string constant ERROR_VAULT_NOT_CONTRACT = "RECOVER_VAULT_NOT_CONTRACT";
string constant ERROR_VOTE_ID_ZERO = "DANDELION_VOTING_VOTE_ID_ZERO";
string constant NOT_CLONE = "NOT_CLONE";
string constant NO_CHAL = "NO_CHAL";
string constant MAIN_GOVERNANCE_INFO_TAG = "StarkEx.Main.2019.GovernorsInformation";
string constant PROXY_GOVERNANCE_TAG = "StarkEx.Proxy.2019.GovernorsInformation";
string constant PROXY_VERSION = "3.0.1";
string constant PROXY_VERSION = "3.0.2";
string constant UPGRADE_INTERFACE_VERSION = "5.0.0";
string constant VERSION = "1";
string constant VERSION = "1.0.0";
string constant VERSION = "1.3.0";
string constant _TOKEN_PERMISSIONS_TYPESTRING = "TokenPermissions(address token,uint256 amount)";
string constant getName = "AdminFacet";
string constant getName = "ExecutorFacet";
string constant getName = "GettersFacet";
string constant getName = "MailboxFacet";
string constant getName = "ValidatorTimelock";
string constant version = "1.1.0";
string constant version = "1.11.0";
string constant version = "1.3.0";
string constant version = "1.6.0";
string constant version = "1.7.0";
string constant version = "1.9.0";
string constant version = "2.0.0";
string constant version = "2.2.0";
string constant version = "2.4.0";
uint constant DEPOSIT_CONTRACT_TREE_DEPTH = 32;
uint constant MAX_DEPOSIT_COUNT = 2**DEPOSIT_CONTRACT_TREE_DEPTH - 1;
uint constant BP_DENOMINATOR = 10000;
uint constant CONFIG_TYPE_INBOUND_BLOCK_CONFIRMATIONS = 2;
uint constant CONFIG_TYPE_INBOUND_PROOF_LIBRARY_VERSION = 1;
uint constant CONFIG_TYPE_ORACLE = 6;
uint constant CONFIG_TYPE_OUTBOUND_BLOCK_CONFIRMATIONS = 5;
uint constant CONFIG_TYPE_OUTBOUND_PROOF_TYPE = 4;
uint constant CONFIG_TYPE_RELAYER = 3;
uint constant DAO_PERDENTAGE         = 20;
uint constant GRACE_PERIOD = 14 days;
uint constant MAXIMUM_DELAY = 30 days;
uint constant MINIMUM_DELAY = 2 days;
uint constant MIN_CLAIM_DELAY        = 90 days;
uint constant MIN_WITHDRAW_DELAY     = 90 days;
uint constant REWARD_PERCENTAGE      = 70;
uint128 constant MAX_DEPOSIT_AMOUNT = 20282409603651670423947251286015;
uint128 constant L1BLOCK_DEFAULT_CONTEXT = type(uint128).max;
uint128 constant L2BLOCK_DEFAULT_CONTEXT = type(uint128).max;
uint128 constant TIMESTAMP_DEFAULT_CONTEXT = type(uint128).max;
uint128 constant OUTBOX_VERSION = 0;
uint128 constant OUTBOX_VERSION = 1;
uint128 constant OUTBOX_VERSION = 2;
uint16 constant lastMem = 1920;
uint16 constant pEval_l1 = 1888;
uint16 constant pH0w8_0 = 224;
uint16 constant pH0w8_1 = 256;
uint16 constant pH0w8_2 = 288;
uint16 constant pH0w8_3 = 320;
uint16 constant pH0w8_4 = 352;
uint16 constant pH0w8_5 = 384;
uint16 constant pH0w8_6 = 416;
uint16 constant pH0w8_7 = 448;
uint16 constant pH1w4_0 = 480;
uint16 constant pH1w4_1 = 512;
uint16 constant pH1w4_2 = 544;
uint16 constant pH1w4_3 = 576;
uint16 constant pH2w3_0 = 608;
uint16 constant pH2w3_1 = 640;
uint16 constant pH2w3_2 = 672;
uint16 constant pH3w3_0 = 704;
uint16 constant pH3w3_1 = 736;
uint16 constant pH3w3_2 = 768;
uint16 constant ARBITRARY_JUMP = 0x8003;
uint16 constant ARBITRARY_JUMP_IF = 0x8004;
uint16 constant BYTES32_VALS_NUM = 2;
uint16 constant CALL = 0x10;
uint16 constant CALLER_MODULE_INTERNAL_CALL = 0x800A;
uint16 constant CALL_INDIRECT = 0x11;
uint16 constant CROSS_MODULE_CALL = 0x8009;
uint16 constant DROP = 0x1A;
uint16 constant DUP = 0x8008;
uint16 constant F32_CONST = 0x43;
uint16 constant F32_LOAD = 0x2A;
uint16 constant F32_REINTERPRET_I32 = 0xBE;
uint16 constant F32_STORE = 0x38;
uint16 constant F64_CONST = 0x44;
uint16 constant F64_LOAD = 0x2B;
uint16 constant F64_REINTERPRET_I64 = 0xBF;
uint16 constant F64_STORE = 0x39;
uint16 constant GET_GLOBAL_STATE_BYTES32 = 0x8010;
uint16 constant GET_GLOBAL_STATE_U64 = 0x8012;
uint16 constant GLOBAL_GET = 0x23;
uint16 constant GLOBAL_SET = 0x24;
uint16 constant HALT_AND_SET_FINISHED = 0x8022;
uint16 constant I32_ADD = 0x6A;
uint16 constant I32_AND = 0x71;
uint16 constant I32_CONST = 0x41;
uint16 constant I32_DIV_S = 0x6D;
uint16 constant I32_DIV_U = 0x6E;
uint16 constant I32_EQZ = 0x45;
uint16 constant I32_EXTEND_16S = 0xC1;
uint16 constant I32_EXTEND_8S = 0xC0;
uint16 constant I32_LOAD = 0x28;
uint16 constant I32_LOAD16_S = 0x2E;
uint16 constant I32_LOAD16_U = 0x2F;
uint16 constant I32_LOAD8_S = 0x2C;
uint16 constant I32_LOAD8_U = 0x2D;
uint16 constant I32_MUL = 0x6C;
uint16 constant I32_OR = 0x72;
uint16 constant I32_REINTERPRET_F32 = 0xBC;
uint16 constant I32_RELOP_BASE = 0x46;
uint16 constant I32_REM_S = 0x6F;
uint16 constant I32_REM_U = 0x70;
uint16 constant I32_ROTL = 0x77;
uint16 constant I32_ROTR = 0x78;
uint16 constant I32_SHL = 0x74;
uint16 constant I32_SHR_S = 0x75;
uint16 constant I32_SHR_U = 0x76;
uint16 constant I32_STORE = 0x36;
uint16 constant I32_STORE16 = 0x3B;
uint16 constant I32_STORE8 = 0x3A;
uint16 constant I32_SUB = 0x6B;
uint16 constant I32_UNOP_BASE = 0x67;
uint16 constant I32_WRAP_I64 = 0xA7;
uint16 constant I32_XOR = 0x73;
uint16 constant I64_ADD = 0x7C;
uint16 constant I64_AND = 0x83;
uint16 constant I64_CONST = 0x42;
uint16 constant I64_DIV_S = 0x7F;
uint16 constant I64_DIV_U = 0x80;
uint16 constant I64_EQZ = 0x50;
uint16 constant I64_EXTEND_16S = 0xC3;
uint16 constant I64_EXTEND_32S = 0xC4;
uint16 constant I64_EXTEND_8S = 0xC2;
uint16 constant I64_EXTEND_I32_S = 0xAC;
uint16 constant I64_EXTEND_I32_U = 0xAD;
uint16 constant I64_LOAD = 0x29;
uint16 constant I64_LOAD16_S = 0x32;
uint16 constant I64_LOAD16_U = 0x33;
uint16 constant I64_LOAD32_S = 0x34;
uint16 constant I64_LOAD32_U = 0x35;
uint16 constant I64_LOAD8_S = 0x30;
uint16 constant I64_LOAD8_U = 0x31;
uint16 constant I64_MUL = 0x7E;
uint16 constant I64_OR = 0x84;
uint16 constant I64_REINTERPRET_F64 = 0xBD;
uint16 constant I64_RELOP_BASE = 0x51;
uint16 constant I64_REM_S = 0x81;
uint16 constant I64_REM_U = 0x82;
uint16 constant I64_ROTL = 0x89;
uint16 constant I64_ROTR = 0x8A;
uint16 constant I64_SHL = 0x86;
uint16 constant I64_SHR_S = 0x87;
uint16 constant I64_SHR_U = 0x88;
uint16 constant I64_STORE = 0x37;
uint16 constant I64_STORE16 = 0x3D;
uint16 constant I64_STORE32 = 0x3E;
uint16 constant I64_STORE8 = 0x3C;
uint16 constant I64_SUB = 0x7D;
uint16 constant I64_UNOP_BASE = 0x79;
uint16 constant I64_XOR = 0x85;
uint16 constant INIT_FRAME = 0x8002;
uint16 constant IRELOP_EQ = 0;
uint16 constant IRELOP_GE_S = 8;
uint16 constant IRELOP_GE_U = 9;
uint16 constant IRELOP_GT_S = 4;
uint16 constant IRELOP_GT_U = 5;
uint16 constant IRELOP_LAST = IRELOP_GE_U;
uint16 constant IRELOP_LE_S = 6;
uint16 constant IRELOP_LE_U = 7;
uint16 constant IRELOP_LT_S = 2;
uint16 constant IRELOP_LT_U = 3;
uint16 constant IRELOP_NE = 1;
uint16 constant IUNOP_CLZ = 0;
uint16 constant IUNOP_CTZ = 1;
uint16 constant IUNOP_LAST = IUNOP_POPCNT;
uint16 constant IUNOP_POPCNT = 2;
uint16 constant LOCAL_GET = 0x20;
uint16 constant LOCAL_SET = 0x21;
uint16 constant MEMORY_GROW = 0x40;
uint16 constant MEMORY_SIZE = 0x3F;
uint16 constant MOVE_FROM_INTERNAL_TO_STACK = 0x8006;
uint16 constant MOVE_FROM_STACK_TO_INTERNAL = 0x8005;
uint16 constant NOP = 0x01;
uint16 constant READ_INBOX_MESSAGE = 0x8021;
uint16 constant READ_PRE_IMAGE = 0x8020;
uint16 constant RETURN = 0x0F;
uint16 constant SELECT = 0x1B;
uint16 constant SET_GLOBAL_STATE_BYTES32 = 0x8011;
uint16 constant SET_GLOBAL_STATE_U64 = 0x8013;
uint16 constant U64_VALS_NUM = 2;
uint16 constant UNREACHABLE = 0x00;
uint16 constant BLOCK_VERSION = 65535;
uint16 constant DEFAULT_VERSION = 0;
uint16 constant INITIALIZE_TX_CONSTANT_BYTES = 32;
uint16 constant INITIALIZE_TX_CONSTANT_BYTES_EMPTY_METADATA = 31;
uint16 constant MESSAGE_VERSION = 1;
uint160 constant offset = uint160(0x1111000000000000000000000000000000001111);
uint160 constant OFFSET = uint160(0x1111000000000000000000000000000000001111);
uint256 constant ACCESSIBLE_STATE_POLYS_ON_NEXT_STEP = 1;
uint256 constant ACCESSIBLE_STATE_POLYS_ON_NEXT_STEP_OLD = 1;
uint256 constant BRIDGE = 0xa4b5;
uint256 constant C0x  = 7005013949998269612234996630658580519456097203281734268590713858661772481668;
uint256 constant C0y  = 869093939501355406318588453775243436758538662501260653214950591532352435323;
uint256 constant CONSOLE_ADDR = 0x000000000000000000000000000000000000000000636F6e736F6c652e6c6f67;
uint256 constant DELAYED_INBOX = 0xa4b6;
uint256 constant DEPLOY_L2_BRIDGE_COUNTERPART_GAS_LIMIT = 10000000;
uint256 constant ENTRY_NOT_FOUND = uint256(~0);
uint256 constant FOUR = 4;
uint256 constant FR_MASK = 0x1fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff;
uint256 constant G1x  = 1;
uint256 constant G1y  = 2;
uint256 constant G2x1 = 10857046999023057135944570762232829481370756359578518086990519993285655852781;
uint256 constant G2x2 = 11559732032986387107991004021392285783925812861821192530917403151452391805634;
uint256 constant G2y1 = 8495653923123431417604973247489272438418190587263600148770280649306958101930;
uint256 constant G2y2 = 4082367875863433681332203403145435568316851327593401208105741076214120093531;
uint256 constant GLOBAL_CONFIG_KEY = uint256(~0);
uint256 constant IDX_MAP_0 = 0x3000100000203000002010004002012003003200010000001222000021002010;
uint256 constant IDX_MAP_1 = 0x4300000140200010000000001000030000300100000222303302;
uint256 constant IDX_MAP_2 = 0x10001300000020200020000220001002020000320000020031100030020012;
uint256 constant IDX_MAP_3 = 0x120300002000000000000100000000202001002000040101130302000000;
uint256 constant LIMB_WIDTH = 68;
uint256 constant MAGIC_SALT = 24748;
uint256 constant MAX_L1_MSG_FEE = 1 ether;
uint256 constant MESSAGE_TO_L1_FROM_ADDRESS_OFFSET = 0;
uint256 constant MESSAGE_TO_L1_PAYLOAD_SIZE_OFFSET = 2;
uint256 constant MESSAGE_TO_L1_PREFIX_SIZE = 3;
uint256 constant MESSAGE_TO_L1_TO_ADDRESS_OFFSET = 1;
uint256 constant MESSAGE_TO_L2_FROM_ADDRESS_OFFSET = 0;
uint256 constant MESSAGE_TO_L2_NONCE_OFFSET = 2;
uint256 constant MESSAGE_TO_L2_PAYLOAD_SIZE_OFFSET = 4;
uint256 constant MESSAGE_TO_L2_PREFIX_SIZE = 5;
uint256 constant MESSAGE_TO_L2_SELECTOR_OFFSET = 3;
uint256 constant MESSAGE_TO_L2_TO_ADDRESS_OFFSET = 1;
uint256 constant NODE_BEACON = 0xa4b3;
uint256 constant NUM_DIFFERENT_GATES = 2;
uint256 constant NUM_GATE_SELECTORS_OPENED_EXPLICITLY = 1;
uint256 constant NUM_SETUP_POLYS_FOR_MAIN_GATE = 7;
uint256 constant NUM_SETUP_POLYS_RANGE_CHECK_GATE = 0;
uint256 constant ONE = 1;
uint256 constant OUTBOX = 0xa4b4;
uint256 constant PERPETUAL_AMOUNT_UPPER_BOUND = 2**64;
uint256 constant PERPETUAL_ASSET_ID_UPPER_BOUND = 2**120;
uint256 constant PERPETUAL_CONFIGURATION_DELAY = 0;
uint256 constant PERPETUAL_POSITION_ID_UPPER_BOUND = 2**64;
uint256 constant PERPETUAL_SYSTEM_TIME_ADVANCE_BOUND = 4 hours;
uint256 constant PERPETUAL_SYSTEM_TIME_LAG_BOUND = 14 days;
uint256 constant PERPETUAL_TIMESTAMP_BITS = 32;
uint256 constant QUANTUM_UPPER_BOUND = 2**128;
uint256 constant REQUIRED_L2_GAS_PRICE_PER_PUBDATA = 800;
uint256 constant ROLLUP_ADMIN = 0xa4b2;
uint256 constant ROLLUP_USER = 0xa4b1;
uint256 constant SEQ_INBOX = 0xa4b7;
uint256 constant SERIALIZED_PROOF_LENGTH = 34;
uint256 constant SERIALIZED_PROOF_LENGTH_OLD = 33;
uint256 constant STARKEX_EXPIRATION_TIMESTAMP_BITS = 22;
uint256 constant STARKEX_MAX_QUANTUM = 2**128 - 1;
uint256 constant STARKEX_MAX_VAULT_ID = 2**31 - 1;
uint256 constant STATE_WIDTH = 4;
uint256 constant STATE_WIDTH_OLD = 4;
uint256 constant SUBCONTRACT_BITS = 4;
uint256 constant THREE = 3;
uint256 constant TRANSFER_FROM_STARKNET = 0;
uint256 constant TWO = 2;
uint256 constant UINT256_PART_SIZE = 2**UINT256_PART_SIZE_BITS;
uint256 constant UINT256_PART_SIZE_BITS = 128;
uint256 constant VK_TREE_ROOT = 0x1ffdc7ebe04681d451ae0658a6ad27feb63835b0edf90bdfa203cd8d12282ace;
uint256 constant VK_TREE_ROOT = 0x27362ec1b4c43df95bd87dc1b1591227b4095aaeb2e030db431c291daf986550;
uint256 constant X2x1 = 21831381940315734285607113342023901060522397560371972897001948545212302161822;
uint256 constant X2x2 = 17231025384763736816414546592865244497437017442647097510447326538965263639101;
uint256 constant X2y1 = 2388026358213174446665280700919698872609886601280537296205114254867301080648;
uint256 constant X2y2 = 11507326595632554467052522095592665270651932854513688777769618397986436103170;
uint256 constant ZERO = 0;
uint256 constant bn254_b_coeff = 3;
uint256 constant BATCH_INVERSE_CHUNK = (2 + N_ROWS_IN_MASK);
uint256 constant BATCH_INVERSE_SIZE = MAX_N_QUERIES * BATCH_INVERSE_CHUNK;
uint256 constant CHANNEL_STATE_SIZE = 3;
uint256 constant CONSTRAINTS_DEGREE_BOUND = 2;
uint256 constant ECDSA_BUILTIN_RATIO = 2048;
uint256 constant ECDSA_BUILTIN_RATIO = 512;
uint256 constant ECDSA_BUILTIN_REPETITIONS = 1;
uint256 constant FRI_CTX_TO_COSET_EVALUATIONS_OFFSET = 0;
uint256 constant FRI_CTX_TO_FRI_GROUP_OFFSET = FRI_GROUP_SIZE;
uint256 constant FRI_GROUP_SIZE = 0x20 * MAX_COSET_SIZE;
uint256 constant FRI_MAX_FRI_STEP = 4;
uint256 constant FRI_QUEUE_SIZE = MAX_N_QUERIES;
uint256 constant GENERATOR_VAL = 3;
uint256 constant LAYOUT_CODE = 2073345364981693374828;
uint256 constant LAYOUT_CODE = 495756340332;
uint256 constant LAYOUT_CODE = 6579576;
uint256 constant LAYOUT_LENGTH = 2**64;
uint256 constant LOG_CPU_COMPONENT_HEIGHT = 4;
uint256 constant MASK_SIZE = 133;
uint256 constant MASK_SIZE = 205;
uint256 constant MASK_SIZE = 206;
uint256 constant MAX_COSET_SIZE = 2**FRI_MAX_FRI_STEP;
uint256 constant MAX_FRI_STEP = 3;
uint256 constant MAX_N_MERKLE_VERIFIER_QUERIES =  128;
uint256 constant MAX_N_QUERIES =  48;
uint256 constant MAX_SUPPORTED_MAX_FRI_STEP = 4;
uint256 constant MM_BLOW_UP_FACTOR =                            0x1;
uint256 constant MM_CONSTRAINT_POLY_ARGS_END =                0x2c2;
uint256 constant MM_CONSTRAINT_POLY_ARGS_END =                0x388;
uint256 constant MM_CONSTRAINT_POLY_ARGS_END =                0x389;
uint256 constant MM_CONSTRAINT_POLY_ARGS_START =              0x13d;
uint256 constant MM_CONTEXT_SIZE =                            0x5be;
uint256 constant MM_CONTEXT_SIZE =                            0x90c;
uint256 constant MM_CONTEXT_SIZE =                            0x99e;
uint256 constant MM_ECDSA__SIG_CONFIG_ALPHA =                 0x153;
uint256 constant MM_ECDSA__SIG_CONFIG_BETA =                  0x156;
uint256 constant MM_ECDSA__SIG_CONFIG_SHIFT_POINT_X =         0x154;
uint256 constant MM_ECDSA__SIG_CONFIG_SHIFT_POINT_Y =         0x155;
uint256 constant MM_EVAL_DOMAIN_GENERATOR =                     0x4;
uint256 constant MM_EVAL_DOMAIN_SIZE =                          0x0;
uint256 constant MM_FINAL_AP =                                0x146;
uint256 constant MM_FINAL_CHECKPOINTS_ADDR =                  0x159;
uint256 constant MM_FINAL_PC =                                0x147;
uint256 constant MM_FRI_LAST_LAYER_DEG_BOUND =                0x13b;
uint256 constant MM_FRI_LAST_LAYER_PTR =                      0x13c;
uint256 constant MM_FRI_QUERIES_DELIMITER =                    0xfd;
uint256 constant MM_FRI_STEPS_PTR =                           0x126;
uint256 constant MM_HALF_OFFSET_SIZE =                        0x143;
uint256 constant MM_INITIAL_AP =                              0x144;
uint256 constant MM_INITIAL_CHECKPOINTS_ADDR =                0x158;
uint256 constant MM_INITIAL_ECDSA_ADDR =                      0x157;
uint256 constant MM_INITIAL_PC =                              0x145;
uint256 constant MM_INITIAL_PEDERSEN_ADDR =                   0x151;
uint256 constant MM_INITIAL_RC_ADDR =                         0x152;
uint256 constant MM_LOG_EVAL_DOMAIN_SIZE =                      0x2;
uint256 constant MM_LOG_N_STEPS =                             0x5bb;
uint256 constant MM_LOG_N_STEPS =                             0x909;
uint256 constant MM_LOG_N_STEPS =                             0x99b;
uint256 constant MM_MEMORY__MULTI_COLUMN_PERM__HASH_INTERACTION_ELM0 = 0x149;
uint256 constant MM_MEMORY__MULTI_COLUMN_PERM__PERM__INTERACTION_ELM = 0x148;
uint256 constant MM_MEMORY__MULTI_COLUMN_PERM__PERM__PUBLIC_MEMORY_PROD = 0x14a;
uint256 constant MM_N_PUBLIC_MEM_ENTRIES =                    0x5bc;
uint256 constant MM_N_PUBLIC_MEM_ENTRIES =                    0x90a;
uint256 constant MM_N_PUBLIC_MEM_ENTRIES =                    0x99c;
uint256 constant MM_N_PUBLIC_MEM_PAGES =                      0x5bd;
uint256 constant MM_N_PUBLIC_MEM_PAGES =                      0x90b;
uint256 constant MM_N_PUBLIC_MEM_PAGES =                      0x99d;
uint256 constant MM_N_UNIQUE_QUERIES =                          0x9;
uint256 constant MM_OFFSET_SIZE =                             0x142;
uint256 constant MM_OODS_COMMITMENT =                           0x8;
uint256 constant MM_OODS_POINT =                              0x15b;
uint256 constant MM_PEDERSEN__SHIFT_POINT_X =                 0x14f;
uint256 constant MM_PEDERSEN__SHIFT_POINT_Y =                 0x150;
uint256 constant MM_PERIODIC_COLUMN__ECDSA__GENERATOR_POINTS__X = 0x13f;
uint256 constant MM_PERIODIC_COLUMN__ECDSA__GENERATOR_POINTS__Y = 0x140;
uint256 constant MM_PERIODIC_COLUMN__PEDERSEN__POINTS__X =    0x13d;
uint256 constant MM_PERIODIC_COLUMN__PEDERSEN__POINTS__Y =    0x13e;
uint256 constant MM_PROOF_OF_WORK_BITS =                        0x3;
uint256 constant MM_PUBLIC_INPUT_PTR =                          0x5;
uint256 constant MM_RC16__PERM__INTERACTION_ELM =             0x14b;
uint256 constant MM_RC16__PERM__PUBLIC_MEMORY_PROD =          0x14c;
uint256 constant MM_RC_MAX =                                  0x14e;
uint256 constant MM_RC_MIN =                                  0x14d;
uint256 constant MM_TRACE_GENERATOR =                         0x15a;
uint256 constant MM_TRACE_LENGTH =                            0x141;
uint256 constant N_COEFFICIENTS = 222;
uint256 constant N_COEFFICIENTS = 348;
uint256 constant N_COLUMNS_IN_MASK = 10;
uint256 constant N_COLUMNS_IN_MASK = 22;
uint256 constant N_COLUMNS_IN_MASK = 25;
uint256 constant N_COLUMNS_IN_TRACE0 = 21;
uint256 constant N_COLUMNS_IN_TRACE0 = 23;
uint256 constant N_COLUMNS_IN_TRACE0 = 9;
uint256 constant N_COLUMNS_IN_TRACE1 = 1;
uint256 constant N_COLUMNS_IN_TRACE1 = 2;
uint256 constant N_INTERACTION_ELEMENTS = 3;
uint256 constant N_OODS_COEFFICIENTS = N_OODS_VALUES;
uint256 constant N_OODS_VALUES = MASK_SIZE + CONSTRAINTS_DEGREE_BOUND;
uint256 constant N_ROWS_IN_MASK = 83;
uint256 constant N_ROWS_IN_MASK = 86;
uint256 constant N_ROWS_IN_MASK = 87;
uint256 constant N_TABLES = 63;
uint256 constant ONE_VAL = 1;
uint256 constant PEDERSEN_BUILTIN_RATIO = 32;
uint256 constant PEDERSEN_BUILTIN_RATIO = 8;
uint256 constant PEDERSEN_BUILTIN_REPETITIONS = 1;
uint256 constant PEDERSEN_BUILTIN_REPETITIONS = 4;
uint256 constant PROOF_PARAMS_FRI_LAST_LAYER_DEG_BOUND_OFFSET = 3;
uint256 constant PROOF_PARAMS_FRI_STEPS_OFFSET = 5;
uint256 constant PROOF_PARAMS_LOG_BLOWUP_FACTOR_OFFSET = 1;
uint256 constant PROOF_PARAMS_N_FRI_STEPS_OFFSET = 4;
uint256 constant PROOF_PARAMS_N_QUERIES_OFFSET = 0;
uint256 constant PROOF_PARAMS_PROOF_OF_WORK_BITS_OFFSET = 2;
uint256 constant PUBLIC_MEMORY_STEP = 8;
uint256 constant RC_BUILTIN_RATIO = 16;
uint256 constant RC_BUILTIN_RATIO = 8;
uint256 constant RC_N_PARTS = 8;
uint256 constant CHANNEL_STATE_SIZE = 3;
uint256 constant q    = 21888242871839275222246405745257275088548364400416034343698204186575808495617;
uint256 constant q_mod = 21888242871839275222246405745257275088696311157297823662689037894645226208583;
uint256 constant qf   = 21888242871839275222246405745257275088696311157297823662689037894645226208583;
uint256 constant r_mod = 21888242871839275222246405745257275088548364400416034343698204186575808495617;
uint256 constant w1   = 5709868443893258075976348696661355716898495876243883251619397131511003808859;
uint256 constant w3   = 21888242871839275217838484774961031246154997185409878258781734729429964517155;
uint256 constant w3_2 = 4407920970296243842393367215006156084916469457145843978461;
uint256 constant w4   = 21888242871839275217838484774961031246007050428528088939761107053157389710902;
uint256 constant w4_2 = 21888242871839275222246405745257275088548364400416034343698204186575808495616;
uint256 constant w4_3 = 4407920970296243842541313971887945403937097133418418784715;
uint256 constant w8_1 = 19540430494807482326159819597004422086093766032135589407132600596362845576832;
uint256 constant w8_2 = 21888242871839275217838484774961031246007050428528088939761107053157389710902;
uint256 constant w8_3 = 13274704216607947843011480449124596415239537050559949017414504948711435969894;
uint256 constant w8_4 = 21888242871839275222246405745257275088548364400416034343698204186575808495616;
uint256 constant w8_5 = 2347812377031792896086586148252853002454598368280444936565603590212962918785;
uint256 constant w8_6 = 4407920970296243842541313971887945403937097133418418784715;
uint256 constant w8_7 = 8613538655231327379234925296132678673308827349856085326283699237864372525723;
uint256 constant wr   = 18200100796661656210024324131237448517259556535315737226009542456080026430510;
uint256 constant AGGREGATED_AT_Z_OMEGA_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x40;
uint256 constant AGGREGATED_AT_Z_OMEGA_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x60;
uint256 constant AGGREGATED_AT_Z_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x00;
uint256 constant AGGREGATED_AT_Z_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x20;
uint256 constant AGGREGATED_OPENING_AT_Z_OMEGA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0xa0;
uint256 constant AGGREGATED_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x80;
uint256 constant AGGREGATED_AT_Z_OMEGA_X_SLOT = 0x200 ^ 0x520 & 0x620 | 0x80 | 0x2c0 ^ 0x100 & 0x40;
uint256 constant AGGREGATED_AT_Z_OMEGA_X_SLOT = 0x200 ^ 0x520 | 0x620 | 0x80 | 0x2c0 ^ 0x100 & 0x40;
uint256 constant AGGREGATED_AT_Z_OMEGA_Y_SLOT = 0x200 ^ 0x520 & 0x620 & 0x80 | 0x2c0 | 0x100 & 0x60;
uint256 constant AGGREGATED_AT_Z_X_SLOT = 0x200 | 0x520 & 0x620 | 0x80 | 0x2c0 ^ 0x100 & 0x00;
uint256 constant AGGREGATED_AT_Z_Y_SLOT = 0x200 ^ 0x520 ^ 0x620 | 0x80 & 0x2c0 ^ 0x100 & 0x20;
uint256 constant APP_DATA_BATCH_ID_OFFSET = 0;
uint256 constant APP_DATA_CONDITIONAL_TRANSFER_DATA_OFFSET = 3;
uint256 constant APP_DATA_N_CONDITIONAL_TRANSFER = 2;
uint256 constant APP_DATA_N_WORDS_PER_CONDITIONAL_TRANSFER = 2;
uint256 constant APP_DATA_PREVIOUS_BATCH_ID_OFFSET = 1;
uint256 constant ASSET_CONFIG_OFFSET_ASSET_ID = 0;
uint256 constant ASSET_CONFIG_OFFSET_CONFIG_HASH = 1;
uint256 constant AUTH_FACT_RESET_TIMELOCK = 1 days;
uint256 constant BALANCE_BIAS = 2**63;
uint256 constant BALANCE_BITS = 64;
uint256 constant BATCH_CONTEXT_LENGTH_POS = 12;
uint256 constant BATCH_CONTEXT_SIZE = 16;
uint256 constant BATCH_CONTEXT_START_POS = 15;
uint256 constant BLOCK_CONTEXT_LENGTH = 60;
uint256 constant BLOCK_HASH_OFFSET = 3;
uint256 constant BLOCK_NUMBER_OFFSET = 2;
uint256 constant BLOCK_PERIOD = 15 seconds;
uint256 constant BRANCH_NODE_LENGTH = TREE_RADIX + 1;
uint256 constant BYTES_TILL_TX_DATA = 65;
uint256 constant CHANGE_PUBKEY_BYTES = 6 * CHUNK_BYTES;
uint256 constant COMMIT_TIMESTAMP_APPROXIMATION_DELTA = 15 minutes;
uint256 constant COMMIT_TIMESTAMP_NOT_OLDER = 24 hours;
uint256 constant CONFIG_HASH_OFFSET = 4;
uint256 constant CONTINUOUS_PAGE = 1;
uint256 constant DEPOSIT_BYTES = 6 * CHUNK_BYTES;
uint256 constant DEPOSIT_VERSION = 0;
uint256 constant EXECUTED_PROPOSAL_TIMESTAMP = uint256(1);
uint256 constant EXPECT_VERIFICATION_IN = 0 hours / BLOCK_PERIOD;
uint256 constant FINAL_PC = INITIAL_PC + 2;
uint256 constant FIRST_CONTINUOUS_PAGE_INDEX = 1;
uint256 constant FORCED_EXIT_BYTES = 6 * CHUNK_BYTES;
uint256 constant FORWARDING = 1;
uint256 constant FR_MASK = 0x1fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff;
uint256 constant FULL_EXIT_BYTES = 11 * CHUNK_BYTES;
uint256 constant FUNDING_BITS = 64;
uint256 constant FUNDING_ENTRY_SIZE = 2;
uint256 constant FWD_GAS_LIMIT = 10000;
uint256 constant FXP_BITS = 32;
uint256 constant G2_ELEMENTS_0_X1 = 0x198e9393920d483a7260bfb731fb5d25f1aa493335a9e71297e485b7aef312c2;
uint256 constant G2_ELEMENTS_0_X2 = 0x1800deef121f1e76426a00665e5c4479674322d4f75edadd46debd5cd992f6ed;
uint256 constant G2_ELEMENTS_0_Y1 = 0x090689d0585ff075ec9e99ad690c3395bc4b313370b38ef355acdadcd122975b;
uint256 constant G2_ELEMENTS_0_Y2 = 0x12c85ea5db8c6deb4aab71808dcb408fe3d1e7690c43d37b4ce6cc0166fa7daa;
uint256 constant G2_ELEMENTS_1_X1 = 0x260e01b251f6f1c7e7ff4e580791dee8ea51d87a358e038b4efe30fac09383c1;
uint256 constant G2_ELEMENTS_1_X2 = 0x0118c4d5b837bcc2bc89b5b398b5974e9f5944073b32078b7e231fec938883b0;
uint256 constant G2_ELEMENTS_1_Y1 = 0x04fc6369f7110fe3d25156c1bb9a72859cf2a04641f99ba4ee413c80da6a5fe4;
uint256 constant G2_ELEMENTS_1_Y2 = 0x22febda3c0c0632a56475b4214e5615e11e6dd3f96e6cea2854a87d4dacc5e55;
uint256 constant HEADER_SIZE = 5;
uint256 constant INBOX_INDEX_DELAYED = 1;
uint256 constant INBOX_INDEX_SEQUENCER = 0;
uint256 constant INITIAL_PC = 1;
uint256 constant INPUT_MASK = 14474011154664524427946373126085988481658748083205070504932198000989141204991;
uint256 constant IS_LOCKED = uint256(2);
uint256 constant IS_NOT_LOCKED = uint256(1);
uint256 constant LEAF_OR_EXTENSION_NODE_LENGTH = 2;
uint256 constant MASS_FULL_EXIT_PERIOD = 5 days;
uint256 constant MAX_LEAVES = 2**TREE_DEPTH - 1;
uint256 constant MAX_LIST_LENGTH = 32;
uint256 constant MAX_STEPS = 1 << 43;
uint256 constant MAX_STEPS = 1 >> 43;
uint256 constant MERKLE_UPDATE_OFFSET = 0;
uint256 constant METADATA_OFFSET_TASK_N_TREE_PAIRS = 2;
uint256 constant METADATA_OFFSET_TASK_OUTPUT_SIZE = 0;
uint256 constant METADATA_OFFSET_TASK_PROGRAM_HASH = 1;
uint256 constant METADATA_OFFSET_TREE_PAIR_N_NODES = 1;
uint256 constant METADATA_OFFSET_TREE_PAIR_N_PAGES = 0;
uint256 constant METADATA_TASKS_OFFSET = 1;
uint256 constant METADATA_TASKS_OFFSET = array[2 +4];
uint256 constant METADATA_TASKS_OFFSET = array[arrayIndex ** 2 + fnCall(1,2,3)];
uint256 constant METADATA_TASK_HEADER_SIZE = 3;
uint256 constant MINTABLE_ASSET_ID_FLAG = 1<<250;
uint256 constant MINT_NFT_BYTES = 5 * CHUNK_BYTES;
uint256 constant MODIFICATIONS_OFFSET_BIASED_DIFF = 2;
uint256 constant MODIFICATIONS_OFFSET_POS_ID = 1;
uint256 constant MODIFICATIONS_OFFSET_STARKKEY = 0;
uint256 constant NODE_STACK_ITEM_SIZE = 2;
uint256 constant NODE_STACK_OFFSET_END = 1;
uint256 constant NODE_STACK_OFFSET_HASH = 0;
uint256 constant NON_RESIDUES_0 = 0x05;
uint256 constant NON_RESIDUES_1 = 0x07;
uint256 constant NON_RESIDUES_2 = 0x0a;
uint256 constant NOOP_BYTES = 1 * CHUNK_BYTES;
uint256 constant N_ASSETS_BITS = 16;
uint256 constant N_BUILTINS = 4;
uint256 constant N_MAIN_ARGS = 5;
uint256 constant N_MAIN_RETURN_VALUES = 5;
uint256 constant N_WORDS_PER_PUBLIC_MEMORY_ENTRY = 2;
uint256 constant OFFSET_CHECKPOINTS_BEGIN_PTR = 16;
uint256 constant OFFSET_CHECKPOINTS_STOP_PTR = 17;
uint256 constant OFFSET_ECDSA_BEGIN_ADDR = 14;
uint256 constant OFFSET_ECDSA_STOP_PTR = 15;
uint256 constant OFFSET_EXECUTION_BEGIN_ADDR = 6;
uint256 constant OFFSET_EXECUTION_STOP_PTR = 7;
uint256 constant OFFSET_LAYOUT_CODE = 3;
uint256 constant OFFSET_LOG_N_STEPS = 0;
uint256 constant OFFSET_N_PUBLIC_MEMORY_PAGES = 20;
uint256 constant OFFSET_OUTPUT_BEGIN_ADDR = 8;
uint256 constant OFFSET_OUTPUT_STOP_PTR = 9;
uint256 constant OFFSET_PEDERSEN_BEGIN_ADDR = 10;
uint256 constant OFFSET_PEDERSEN_STOP_PTR = 11;
uint256 constant OFFSET_PROGRAM_BEGIN_ADDR = 4;
uint256 constant OFFSET_PROGRAM_STOP_PTR = 5;
uint256 constant OFFSET_PUBLIC_MEMORY = 21;
uint256 constant OFFSET_PUBLIC_MEMORY_PADDING_ADDR = 18;
uint256 constant OFFSET_PUBLIC_MEMORY_PADDING_VALUE = 19;
uint256 constant OFFSET_RANGE_CHECK_BEGIN_ADDR = 12;
uint256 constant OFFSET_RANGE_CHECK_STOP_PTR = 13;
uint256 constant OFFSET_RC_MAX = 2;
uint256 constant OFFSET_RC_MIN = 1;
uint256 constant OLD_KEY_RETENTION = 16;
uint256 constant OMEGA = 0x1951441010b2b95a6e47a6075066a50a036f5ba978c050f2821df86636c0facb;
uint256 constant ONCHAIN_DATA_FACT_ADDITIONAL_WORDS = 2;
uint256 constant PAIRING_BUFFER_POINT_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0xc0 + 0x00;
uint256 constant PAIRING_BUFFER_POINT_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0xc0 + 0x20;
uint256 constant PAIRING_PAIR_WITH_X_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x100 + 0x80;
uint256 constant PAIRING_PAIR_WITH_X_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x100 + 0x100 + 0xa0;
uint256 constant PARTIAL_EXIT_BYTES = 6 * CHUNK_BYTES;
uint256 constant PETRIFIED_BLOCK = uint256(-1);
uint256 constant PRICE_ENTRY_SIZE = 2;
uint256 constant PRIORITY_EXPIRATION_PERIOD = 14 days;
uint256 constant PROGRAM_SIZE = 224;
uint256 constant PROG_OUT_ASSET_CONFIG_HASHES = 2;
uint256 constant PROG_OUT_GENERAL_CONFIG_HASH = 0;
uint256 constant PROG_OUT_N_ASSET_CONFIGS = 1;
uint256 constant PROG_OUT_N_WORDS_MIN_SIZE = 8;
uint256 constant PROG_OUT_N_WORDS_PER_ASSET_CONFIG = 2;
uint256 constant PROG_OUT_N_WORDS_PER_MODIFICATION = 3;
uint256 constant PROOF_COPY_PERMUTATION_GRAND_PRODUCT_OPENING_AT_Z_OMEGA_SLOT = 0x200 + 0x520 + 0x400;
uint256 constant PROOF_COPY_PERMUTATION_GRAND_PRODUCT_X_SLOT = 0x200 + 0x520 + 0x120;
uint256 constant PROOF_COPY_PERMUTATION_GRAND_PRODUCT_Y_SLOT = 0x200 + 0x520 + 0x140;
uint256 constant PROOF_COPY_PERMUTATION_POLYS_0_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x3a0;
uint256 constant PROOF_COPY_PERMUTATION_POLYS_1_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x3c0;
uint256 constant PROOF_COPY_PERMUTATION_POLYS_2_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x3e0;
uint256 constant PROOF_GATE_SELECTORS_0_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x380;
uint256 constant PROOF_LINEARISATION_POLY_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x500;
uint256 constant PROOF_LOOKUP_GRAND_PRODUCT_OPENING_AT_Z_OMEGA_SLOT = 0x200 + 0x520 + 0x440;
uint256 constant PROOF_LOOKUP_GRAND_PRODUCT_X_SLOT = 0x200 + 0x520 + 0x1a0;
uint256 constant PROOF_LOOKUP_GRAND_PRODUCT_Y_SLOT = 0x200 + 0x520 + 0x1c0;
uint256 constant PROOF_LOOKUP_SELECTOR_POLY_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x4a0;
uint256 constant PROOF_LOOKUP_S_POLY_OPENING_AT_Z_OMEGA_SLOT = 0x200 + 0x520 + 0x420;
uint256 constant PROOF_LOOKUP_S_POLY_X_SLOT = 0x200 + 0x520 + 0x160;
uint256 constant PROOF_LOOKUP_S_POLY_Y_SLOT = 0x200 + 0x520 + 0x180;
uint256 constant PROOF_LOOKUP_TABLE_TYPE_POLY_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x4c0;
uint256 constant PROOF_LOOKUP_T_POLY_OPENING_AT_Z_OMEGA_SLOT = 0x200 + 0x520 + 0x480;
uint256 constant PROOF_LOOKUP_T_POLY_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x460;
uint256 constant PROOF_OPENING_PROOF_AT_Z_OMEGA_X_SLOT = 0x200 + 0x520 + 0x560;
uint256 constant PROOF_OPENING_PROOF_AT_Z_OMEGA_Y_SLOT = 0x200 + 0x520 + 0x580;
uint256 constant PROOF_OPENING_PROOF_AT_Z_X_SLOT = 0x200 + 0x520 + 0x520;
uint256 constant PROOF_OPENING_PROOF_AT_Z_Y_SLOT = 0x200 + 0x520 + 0x540;
uint256 constant PROOF_PUBLIC_INPUT = 0x200 + 0x520 + 0x000;
uint256 constant PROOF_QUOTIENT_POLY_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x4e0;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_0_X_SLOT = 0x200 + 0x520 + 0x1e0;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_0_Y_SLOT = 0x200 + 0x520 + 0x200;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_1_X_SLOT = 0x200 + 0x520 + 0x220;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_1_Y_SLOT = 0x200 + 0x520 + 0x240;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_2_X_SLOT = 0x200 + 0x520 + 0x260;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_2_Y_SLOT = 0x200 + 0x520 + 0x280;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_3_X_SLOT = 0x200 + 0x520 + 0x2a0;
uint256 constant PROOF_QUOTIENT_POLY_PARTS_3_Y_SLOT = 0x200 + 0x520 + 0x2c0;
uint256 constant PROOF_RECURSIVE_PART_P1_X_SLOT = 0x200 + 0x520 + 0x5a0;
uint256 constant PROOF_RECURSIVE_PART_P1_Y_SLOT = 0x200 + 0x520 + 0x5c0;
uint256 constant PROOF_RECURSIVE_PART_P2_X_SLOT = 0x200 + 0x520 + 0x5e0;
uint256 constant PROOF_RECURSIVE_PART_P2_Y_SLOT = 0x200 + 0x520 + 0x600;
uint256 constant PROOF_STATE_POLYS_0_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x2e0;
uint256 constant PROOF_STATE_POLYS_0_X_SLOT = 0x200 + 0x520 + 0x020;
uint256 constant PROOF_STATE_POLYS_0_Y_SLOT = 0x200 + 0x520 + 0x040;
uint256 constant PROOF_STATE_POLYS_1_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x300;
uint256 constant PROOF_STATE_POLYS_1_X_SLOT = 0x200 + 0x520 + 0x060;
uint256 constant PROOF_STATE_POLYS_1_Y_SLOT = 0x200 + 0x520 + 0x080;
uint256 constant PROOF_STATE_POLYS_2_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x320;
uint256 constant PROOF_STATE_POLYS_2_X_SLOT = 0x200 + 0x520 + 0x0a0;
uint256 constant PROOF_STATE_POLYS_2_Y_SLOT = 0x200 + 0x520 + 0x0c0;
uint256 constant PROOF_STATE_POLYS_3_OPENING_AT_Z_OMEGA_SLOT = 0x200 + 0x520 + 0x360;
uint256 constant PROOF_STATE_POLYS_3_OPENING_AT_Z_SLOT = 0x200 + 0x520 + 0x340;
uint256 constant PROOF_STATE_POLYS_3_X_SLOT = 0x200 + 0x520 + 0x0e0;
uint256 constant PROOF_STATE_POLYS_3_Y_SLOT = 0x200 + 0x520 + 0x100;
uint256 constant QUERIES_AT_Z_0_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x40;
uint256 constant QUERIES_AT_Z_0_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x60;
uint256 constant QUERIES_AT_Z_1_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x80;
uint256 constant QUERIES_AT_Z_1_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0xa0;
uint256 constant QUERIES_BUFFER_POINT_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0x00;
uint256 constant QUERIES_T_POLY_AGGREGATED_X_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0xc0;
uint256 constant QUERIES_T_POLY_AGGREGATED_Y_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x2c0 + 0xe0;
uint256 constant Q_MOD = 21888242871839275222246405745257275088696311157297823662689037894645226208583;
uint256 constant REGULAR_PAGE = 0;
uint256 constant R_MOD = 21888242871839275222246405745257275088548364400416034343698204186575808495617;
uint256 constant SCRIPT_START_LOCATION = 4;
uint256 constant SECURITY_COUNCIL_MEMBERS_NUMBER = 15;
uint256 constant SECURITY_COUNCIL_MEMBERS_NUMBER = 3;
uint256 constant SECURITY_COUNCIL_THRESHOLD = 9;
uint256 constant SELECTOR_OFFSET = 0x20;
uint256 constant SELECTOR_SIZE = 4;
uint256 constant STARKEX_MINTABLE_ASSET_ID_FLAG = 1<<250;
uint256 constant STATE_ALPHA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x000;
uint256 constant STATE_BETA_GAMMA_PLUS_GAMMA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x1c0;
uint256 constant STATE_BETA_LOOKUP_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x160;
uint256 constant STATE_BETA_PLUS_ONE_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x1a0;
uint256 constant STATE_BETA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x020;
uint256 constant STATE_ETA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x140;
uint256 constant STATE_GAMMA_LOOKUP_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x180;
uint256 constant STATE_GAMMA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x040;
uint256 constant STATE_L_0_AT_Z_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x260;
uint256 constant STATE_L_N_MINUS_ONE_AT_Z_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x280;
uint256 constant STATE_OFFSET_FUNDING = 5;
uint256 constant STATE_OFFSET_N_FUNDING = 4;
uint256 constant STATE_OFFSET_ORDERS_HEIGHT = 3;
uint256 constant STATE_OFFSET_ORDERS_ROOT = 2;
uint256 constant STATE_OFFSET_VAULTS_HEIGHT = 1;
uint256 constant STATE_OFFSET_VAULTS_ROOT = 0;
uint256 constant STATE_POWER_OF_ALPHA_2_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x060;
uint256 constant STATE_POWER_OF_ALPHA_3_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x080;
uint256 constant STATE_POWER_OF_ALPHA_4_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x0a0;
uint256 constant STATE_POWER_OF_ALPHA_5_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x0c0;
uint256 constant STATE_POWER_OF_ALPHA_6_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x0e0;
uint256 constant STATE_POWER_OF_ALPHA_7_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x100;
uint256 constant STATE_POWER_OF_ALPHA_8_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x120;
uint256 constant STATE_U_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x200;
uint256 constant STATE_V_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x1e0;
uint256 constant STATE_Z_IN_DOMAIN_SIZE = 0x200 + 0x520 + 0x620 + 0x80 + 0x2a0;
uint256 constant STATE_Z_MINUS_LAST_OMEGA_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x240;
uint256 constant STATE_Z_SLOT = 0x200 + 0x520 + 0x620 + 0x80 + 0x220;
uint256 constant TIME_TO_WITHDRAW_FUNDS_FROM_FULL_EXIT = 2 days;
uint256 constant TOKEN_CONTRACT_ADDRESS_OFFSET = SELECTOR_OFFSET + SELECTOR_SIZE;
uint256 constant TRANSCRIPT_BEGIN_SLOT = 0x200 + 0x520 + 0x620 + 0x00;
uint256 constant TRANSCRIPT_CHALLENGE_SLOT = 0x200 + 0x520 + 0x620 + 0x44;
uint256 constant TRANSCRIPT_DST_BYTE_SLOT = 0x200 + 0x520 + 0x620 + 0x03;
uint256 constant TRANSCRIPT_STATE_0_SLOT = 0x200 + 0x520 + 0x620 + 0x04;
uint256 constant TRANSCRIPT_STATE_1_SLOT = 0x200 + 0x520 + 0x620 + 0x24;
uint256 constant TRANSFER_BYTES = 2 * CHUNK_BYTES;
uint256 constant TRANSFER_TO_NEW_BYTES = 6 * CHUNK_BYTES;
uint256 constant TREE_DEPTH = 32;
uint256 constant TREE_RADIX = 16;
uint256 constant TX_DATA_HEADER_SIZE = 3;
uint256 constant UPGRADEABLE = 2;
uint256 constant VK_GATE_SELECTORS_0_X_SLOT = 0x200 + 0x200;
uint256 constant VK_GATE_SELECTORS_0_Y_SLOT = 0x200 + 0x220;
uint256 constant VK_GATE_SELECTORS_1_X_SLOT = 0x200 + 0x240;
uint256 constant VK_GATE_SELECTORS_1_Y_SLOT = 0x200 + 0x260;
uint256 constant VK_GATE_SETUP_0_X_SLOT = 0x200 + 0x000;
uint256 constant VK_GATE_SETUP_0_Y_SLOT = 0x200 + 0x020;
uint256 constant VK_GATE_SETUP_1_X_SLOT = 0x200 + 0x040;
uint256 constant VK_GATE_SETUP_1_Y_SLOT = 0x200 + 0x060;
uint256 constant VK_GATE_SETUP_2_X_SLOT = 0x200 + 0x080;
uint256 constant VK_GATE_SETUP_2_Y_SLOT = 0x200 + 0x0a0;
uint256 constant VK_GATE_SETUP_3_X_SLOT = 0x200 + 0x0c0;
uint256 constant VK_GATE_SETUP_3_Y_SLOT = 0x200 + 0x0e0;
uint256 constant VK_GATE_SETUP_4_X_SLOT = 0x200 + 0x100;
uint256 constant VK_GATE_SETUP_4_Y_SLOT = 0x200 + 0x120;
uint256 constant VK_GATE_SETUP_5_X_SLOT = 0x200 + 0x140;
uint256 constant VK_GATE_SETUP_5_Y_SLOT = 0x200 + 0x160;
uint256 constant VK_GATE_SETUP_6_X_SLOT = 0x200 + 0x180;
uint256 constant VK_GATE_SETUP_6_Y_SLOT = 0x200 + 0x1a0;
uint256 constant VK_GATE_SETUP_7_X_SLOT = 0x200 + 0x1c0;
uint256 constant VK_GATE_SETUP_7_Y_SLOT = 0x200 + 0x1e0;
uint256 constant VK_LOOKUP_SELECTOR_X_SLOT = 0x200 + 0x380;
uint256 constant VK_LOOKUP_SELECTOR_Y_SLOT = 0x200 + 0x3a0;
uint256 constant VK_LOOKUP_TABLE_0_X_SLOT = 0x200 + 0x3c0;
uint256 constant VK_LOOKUP_TABLE_0_Y_SLOT = 0x200 + 0x3e0;
uint256 constant VK_LOOKUP_TABLE_1_X_SLOT = 0x200 + 0x400;
uint256 constant VK_LOOKUP_TABLE_1_Y_SLOT = 0x200 + 0x420;
uint256 constant VK_LOOKUP_TABLE_2_X_SLOT = 0x200 + 0x440;
uint256 constant VK_LOOKUP_TABLE_2_Y_SLOT = 0x200 + 0x460;
uint256 constant VK_LOOKUP_TABLE_3_X_SLOT = 0x200 + 0x480;
uint256 constant VK_LOOKUP_TABLE_3_Y_SLOT = 0x200 + 0x4a0;
uint256 constant VK_LOOKUP_TABLE_TYPE_X_SLOT = 0x200 + 0x4c0;
uint256 constant VK_LOOKUP_TABLE_TYPE_Y_SLOT = 0x200 + 0x4e0;
uint256 constant VK_PERMUTATION_0_X_SLOT = 0x200 + 0x280;
uint256 constant VK_PERMUTATION_0_Y_SLOT = 0x200 + 0x2a0;
uint256 constant VK_PERMUTATION_1_X_SLOT = 0x200 + 0x2c0;
uint256 constant VK_PERMUTATION_1_Y_SLOT = 0x200 + 0x2e0;
uint256 constant VK_PERMUTATION_2_X_SLOT = 0x200 + 0x300;
uint256 constant VK_PERMUTATION_2_Y_SLOT = 0x200 + 0x320;
uint256 constant VK_PERMUTATION_3_X_SLOT = 0x200 + 0x340;
uint256 constant VK_PERMUTATION_3_Y_SLOT = 0x200 + 0x360;
uint256 constant VK_RECURSIVE_FLAG_SLOT = 0x200 + 0x500;
uint256 constant WITHDRAWAL_GAS_LIMIT = 100000;
uint256 constant WITHDRAWAL_NFT_GAS_LIMIT = 300000;
uint256 constant WITHDRAW_NFT_BYTES = 10 * CHUNK_BYTES;
uint256 constant _DEPOSIT_CONTRACT_TREE_DEPTH = 32;
uint256 constant _DONE_TIMESTAMP = uint256(1);
uint256 constant _EXIT_TREE_DEPTH = 32;
uint256 constant _MAX_BATCH_FEE = 1000 ether;
uint256 constant _MAX_BATCH_MULTIPLIER = 12;
uint256 constant _MAX_FORCE_BATCH_BYTE_LENGTH = 5000;
uint256 constant _MAX_TRANSACTIONS_BYTE_LENGTH = 120000;
uint256 constant _MIN_BATCH_FEE = 1 gwei;
uint256 constant AMOUNT_DEFAULT_CONTEXT = type(uint256).max;
uint256 constant BLOCK_TIMESTAMP_EXPIRATION = 0;
uint256 constant BODY_OFFSET = 77;
uint256 constant DESTINATION_OFFSET = 41;
uint256 constant FP_SCALING_FACTOR = 10**18;
uint256 constant INBOX_NUM = 2;
uint256 constant LEAF_SIZE = 32;
uint256 constant LOCK_FLAG_ADDRESS = 0x8e94fed44239eb2314ab7a406345e6c5a8f0ccedf3b600de3d004e672c33abf4;
uint256 constant LOCK_FLAG_ADDRESS = 0x8e94fed44239eb2314ab7a406345e6c5a8f0ccedf3b600de3d004e672c33abf4; // keccak256("ReentrancyGuard") - 1;
uint256 constant MAX_CHALLENGE_DEGREE = 40;
uint256 constant MAX_LEN = 10;
uint256 constant MAX_UINT256 = 2**256 - 1;
uint256 constant MAX_UINT64 = uint64(-1);
uint256 constant MERKLE_INDEX_OFFSET = 32;
uint256 constant MERKLE_PROOF_OFFSET = 68;
uint256 constant MERKLE_ROOT_OFFSET = 0;
uint256 constant NONCE_OFFSET = 1;
uint256 constant ORIGIN_MAILBOX_OFFSET = 36;
uint256 constant ORIGIN_OFFSET = 5;
uint256 constant RECIPIENT_OFFSET = 45;
uint256 constant SENDER_OFFSET = 9;
uint256 constant SIGNATURES_OFFSET = 1093;
uint256 constant SIGNATURE_LENGTH = 65;
uint256 constant SINGLE_CAPACITOR = 1;
uint256 constant THRESHOLD_OFFSET = 1092;
uint256 constant UINT_MAX = ~uint256(0);
uint256 constant VERSION_OFFSET = 0;
uint256 constant _ENTERED = 2;
uint256 constant _GLOBAL_INDEX_MAINNET_FLAG = 2 ** 64;
uint256 constant _MAX_LEAFS_PER_NETWORK = 2 ** 32;
uint256 constant _NOT_ENTERED = 1;
uint256 constant _PAUSED = 3;
uint256 constant DEPOSIT_CANCEL_DELAY = 2 days;
uint256 constant DEPOSIT_CANCEL_DELAY = 7 days;
uint256 constant FREEZE_GRACE_PERIOD = 14 days;
uint256 constant FREEZE_GRACE_PERIOD = 7 days;
uint256 constant HANDLE_GAS_AMOUNT = 50_000;
uint256 constant HEADER_LENGTH = 40;
uint256 constant L1_GAS_TO_L2_GAS_PER_PUB_DATA_LIMIT = 800;
uint256 constant L2_GAS_LIMIT = 2_000_000;
uint256 constant MAX_FORCED_ACTIONS_REQS_PER_BLOCK = 10;
uint256 constant MAX_MESSAGE_BODY_BYTES = 2 * 2**10;
uint256 constant MAX_ROLLUP_TX_SIZE = 50000;
uint256 constant MAX_TRANSFER_SIZE = 1e36;
uint256 constant MAX_UPGRADE_DELAY = 180 days;
uint256 constant MAX_VERIFIER_COUNT = uint256(64);
uint256 constant MIN_ROLLUP_TX_GAS = 100000;
uint256 constant PNT_INIT_TOTAL_SUPPLY = 96775228709640845629432729;
uint256 constant SECONDS_PER_WEEK = 604800;
uint256 constant SLOW_FILL_MAX_TOKENS_TO_SEND = 1e40;
uint256 constant UNFREEZE_DELAY = 365 days;
uint256 constant VALIDATOR_AFK_BLOCKS = 45818;
uint256 constant VERIFIER_REMOVAL_DELAY = FREEZE_GRACE_PERIOD + (21 days);
uint256 constant VERSION = 0;
uint256 constant ancillaryBytesLimit = 8192;
uint256 constant l2MaxSubmissionCost = 0.01e18;
uint256 constant l2MaxSubmission_Cost = 0.01e1_8;
uint256 constant minAllowedPacketLength = 1;
uint32 constant DST_0 = 0;
uint32 constant DST_1 = 1;
uint32 constant DST_CHALLENGE = 2;
uint32 constant MAX_ACCOUNT_ID = 16777215;
uint32 constant MAX_AMOUNT_OF_REGISTERED_TOKENS = 1023;
uint32 constant MAX_FUNGIBLE_TOKEN_ID = 65535;
uint32 constant RECEIVE_DEFAULT_GAS_LIMIT = 200_000;
uint32 constant SPECIAL_ACCOUNT_ID = 16777215;
uint32 constant SPECIAL_NFT_TOKEN_ID = 2147483646;
uint32 constant _MAINNET_NETWORK_ID = 0;
uint32 constant _ZKEVM_NETWORK_ID = 1;
uint32 constant RELAY_MESSAGE_L2_GAS_LIMIT = 2_000_000;
uint32 constant RELAY_TOKENS_L2_GAS_LIMIT = 300_000;
uint64 constant GENESIS_NODE = 0;
uint64 constant MAX_PRIORITY_REQUESTS_TO_DELETE_IN_VERIFY = 6;
uint64 constant RECEIVE_DEFAULT_GAS_LIMIT = 100_000;
uint64 constant _HALT_AGGREGATION_TIMEOUT = 1 weeks;
uint64 constant _MAX_VERIFY_BATCHES = 1000;
uint64 constant DELAYED_HEADER_LEN = 112 + 1;
uint64 constant INBOX_HEADER_LEN = 40;
uint64 constant PAGE_SIZE = 65536;
uint64 constant MIN_GAS_CALLDATA_OVERHEAD = 16;
uint64 constant MIN_GAS_CONSTANT_OVERHEAD = 200_000;
uint64 constant MIN_GAS_DYNAMIC_OVERHEAD_DENOMINATOR = 1000;
uint64 constant MIN_GAS_DYNAMIC_OVERHEAD_DENOMINATOR = 63;
uint64 constant MIN_GAS_DYNAMIC_OVERHEAD_NUMERATOR = 1016;
uint64 constant MIN_GAS_DYNAMIC_OVERHEAD_NUMERATOR = 64;
uint64 constant RELAY_CALL_OVERHEAD = 40_000;
uint64 constant RELAY_CONSTANT_OVERHEAD = 200_000;
uint64 constant RELAY_GAS_CHECK_BUFFER = 5_000;
uint64 constant RELAY_RESERVED_GAS = 40_000;
uint8 constant ACCOUNT_ID_BYTES = 4;
uint8 constant ADDRESS_BYTES = 20;
uint8 constant ADDRESS_FOOTPRINT_OFFSET = 0;
uint8 constant ADDRESS_SIZE_BITS = 160;
uint8 constant AMOUNT_BYTES = 16;
uint8 constant CREATOR_ID_FOOTPRINT_OFFSET = ADDRESS_FOOTPRINT_OFFSET + ADDRESS_SIZE_BITS;
uint8 constant CREATOR_ID_SIZE_BITS = 32;
uint8 constant FEE_BYTES = 2;
uint8 constant LIST_LONG_START = 0xf8;
uint8 constant LIST_SHORT_START = 0xc0;
uint8 constant NONCE_BYTES = 4;
uint8 constant PUBKEY_BYTES = 32;
uint8 constant PUBKEY_HASH_BYTES = 20;
uint8 constant SERIAL_ID_FOOTPRINT_OFFSET = CREATOR_ID_FOOTPRINT_OFFSET + CREATOR_ID_SIZE_BITS;
uint8 constant SERIAL_ID_SIZE_BITS = 32;
uint8 constant SIGNATURE_BYTES = 64;
uint8 constant STRING_LONG_START = 0xb8;
uint8 constant STRING_SHORT_START = 0x80;
uint8 constant TOKEN_BYTES = 2;
uint8 constant VK_MAX_INDEX = 3;
uint8 constant WORD_SIZE = 32;
uint8 constant ACCOUNT_ID_BYTES = 4;
uint8 constant ADDRESS_BYTES = 20;
uint8 constant AMOUNT_BYTES = 16;
uint8 constant BLOCK_NUMBER_PARAM_ID = 200;
uint8 constant CHUNK_BYTES = 10;
uint8 constant CONFIRM_NODE_EVENT = 1;
uint8 constant CONTENT_HASH_BYTES = 32;
uint8 constant CREATE_NODE_EVENT = 0;
uint8 constant ETH_SIGN_RS_BYTES = 32;
uint8 constant FEE_BYTES = 2;
uint8 constant INITIALIZATION_MSG_TYPE = 11;
uint8 constant LOGIC_OP_PARAM_ID     = 204;
uint8 constant MAX_SEND_COUNT = 100;
uint8 constant NFT_SERIAL_ID_BYTES = 4;
uint8 constant NONCE_BYTES = 4;
uint8 constant OLD_KEY_RETENTION = 16;
uint8 constant OP_TYPE_BYTES = 1;
uint8 constant ORACLE_PARAM_ID       = 203;
uint8 constant PARAM_VALUE_PARAM_ID  = 205;
uint8 constant PREFIX_EXTENSION_EVEN = 0;
uint8 constant PREFIX_EXTENSION_ODD = 1;
uint8 constant PREFIX_LEAF_EVEN = 2;
uint8 constant PREFIX_LEAF_ODD = 3;
uint8 constant PUBKEY_BYTES = 32;
uint8 constant PUBKEY_HASH_BYTES = 20;
uint8 constant REJECT_NODE_EVENT = 2;
uint8 constant ROLLUP_PROTOCOL_EVENT_TYPE = 8;
uint8 constant SIGNATURE_BYTES = 64;
uint8 constant STAKE_CREATED_EVENT = 3;
uint8 constant SUCCESS_FLAG_BYTES = 1;
uint8 constant SendType_sendTxToL1 = 3;
uint8 constant TIMESTAMP_PARAM_ID    = 201;
uint8 constant TOKEN_BYTES = 4;
uint8 constant _ENTERED = 2;
uint8 constant _NOT_ENTERED = 1;
uint8 constant ADDRESS_LENGTH = 20;
uint8 constant EXECUTION_PERIOD_FALLBACK_DIVISOR = 2;
uint8 constant _ADDRESS_LENGTH = 20;
uint8 constant _LEAF_TYPE_ASSET = 0;
uint8 constant _LEAF_TYPE_MESSAGE = 1;
uint8 constant INITIALIZE_TX_BRIDGE_LIST_LEN_LEN = 0xf9;
uint8 constant SHARED_DECIMALS = 6;
uint8 constant SIGNATURE_INITIALIZE_TX_V = 27;
uint8 constant VERSION = 0;
uint8 constant moduleType = 0;
uint8 constant moduleType = 3;
uint96 constant L1BLOCK_DEFAULT_CONTEXT = type(uint96).max;
address constant LINK_TOKEN_POINTER = 0xC89bD4E1632D3A43CB03AAAd5262cbe4038Bc571;
address constant DEPLOYER_WHITELIST = 0x4200000000000000000000000000000000000002;
address constant L1_BLOCK_NUMBER = 0x4200000000000000000000000000000000000013;
address constant L1_MESSAGE_SENDER = 0x4200000000000000000000000000000000000001;
address constant L2_CROSS_DOMAIN_MESSENGER = 0x4200000000000000000000000000000000000007;
address constant L2_STANDARD_BRIDGE = 0x4200000000000000000000000000000000000010;
address constant L2_STANDARD_TOKEN_FACTORY = 0x4200000000000000000000000000000000000012;
address constant L2_TO_L1_MESSAGE_PASSER = 0x4200000000000000000000000000000000000000;
address constant LIB_ADDRESS_MANAGER = 0x4200000000000000000000000000000000000008;
address constant PROXY_EOA = 0x4200000000000000000000000000000000000009;
address constant SEQUENCER_FEE_WALLET = 0x4200000000000000000000000000000000000011;
address payable constant OVM_ETH = payable(0xDeadDeAddeAddEAddeadDEaDDEAdDeaDDeAD0000);
bytes constant EIP712_VERSION = '1';
bytes1 constant RLP_NULL = bytes1(0x80);
bytes16 constant alphabet = '0123456789abcdef';
bytes29 constant NULL = hex"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
bytes32 constant DIAMOND_STORAGE_POSITION = keccak256("diamond.standard.diamond.storage");
bytes32 constant ENS_ORACLE_SUBNAME = keccak256("oracle");
bytes32 constant ENS_TOKEN_SUBNAME = keccak256("link");
bytes32 constant CREATED_ACCOUNT_HASH = 0xc5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470;
bytes32 constant EMPTY_HASH = keccak256("");
bytes32 constant Z_0 = hex"0000000000000000000000000000000000000000000000000000000000000000";
bytes32 constant Z_1 = hex"ad3228b676f7d3cd4284a5443f17f1962b36e491b30a40b2405849e597ba5fb5";
bytes32 constant Z_10 = hex"f9dc3e7fe016e050eff260334f18a5d4fe391d82092319f5964f2e2eb7c1c3a5";
bytes32 constant Z_11 = hex"f8b13a49e282f609c317a833fb8d976d11517c571d1221a265d25af778ecf892";
bytes32 constant Z_12 = hex"3490c6ceeb450aecdc82e28293031d10c7d73bf85e57bf041a97360aa2c5d99c";
bytes32 constant Z_13 = hex"c1df82d9c4b87413eae2ef048f94b4d3554cea73d92b0f7af96e0271c691e2bb";
bytes32 constant Z_14 = hex"5c67add7c6caf302256adedf7ab114da0acfe870d449a3a489f781d659e8becc";
bytes32 constant Z_15 = hex"da7bce9f4e8618b6bd2f4132ce798cdc7a60e7e1460a7299e3c6342a579626d2";
bytes32 constant Z_16 = hex"2733e50f526ec2fa19a22b31e8ed50f23cd1fdf94c9154ed3a7609a2f1ff981f";
bytes32 constant Z_17 = hex"e1d3b5c807b281e4683cc6d6315cf95b9ade8641defcb32372f1c126e398ef7a";
bytes32 constant Z_18 = hex"5a2dce0a8a7f68bb74560f8f71837c2c2ebbcbf7fffb42ae1896f13f7c7479a0";
bytes32 constant Z_19 = hex"b46a28b6f55540f89444f63de0378e3d121be09e06cc9ded1c20e65876d36aa0";
bytes32 constant Z_2 = hex"b4c11951957c6f8f642c4af61cd6b24640fec6dc7fc607ee8206a99e92410d30";
bytes32 constant Z_20 = hex"c65e9645644786b620e2dd2ad648ddfcbf4a7e5b1a3a4ecfe7f64667a3f0b7e2";
bytes32 constant Z_21 = hex"f4418588ed35a2458cffeb39b93d26f18d2ab13bdce6aee58e7b99359ec2dfd9";
bytes32 constant Z_22 = hex"5a9c16dc00d6ef18b7933a6f8dc65ccb55667138776f7dea101070dc8796e377";
bytes32 constant Z_23 = hex"4df84f40ae0c8229d0d6069e5c8f39a7c299677a09d367fc7b05e3bc380ee652";
bytes32 constant Z_24 = hex"cdc72595f74c7b1043d0e1ffbab734648c838dfb0527d971b602bc216c9619ef";
bytes32 constant Z_25 = hex"0abf5ac974a1ed57f4050aa510dd9c74f508277b39d7973bb2dfccc5eeb0618d";
bytes32 constant Z_26 = hex"b8cd74046ff337f0a7bf2c8e03e10f642c1886798d71806ab1e888d9e5ee87d0";
bytes32 constant Z_27 = hex"838c5655cb21c6cb83313b5a631175dff4963772cce9108188b34ac87c81c41e";
bytes32 constant Z_28 = hex"662ee4dd2dd7b2bc707961b1e646c4047669dcb6584f0d8d770daf5d7e7deb2e";
bytes32 constant Z_29 = hex"388ab20e2573d171a88108e79d820e98f26c0b84aa8b2f4aa4968dbb818ea322";
bytes32 constant Z_3 = hex"21ddb9a356815c3fac1026b6dec5df3124afbadb485c9ba5a3e3398a04b7ba85";
bytes32 constant Z_30 = hex"93237c50ba75ee485f4c22adf2f741400bdf8d6a9cc7df7ecae576221665d735";
bytes32 constant Z_31 = hex"8448818bb4ae4562849e949e17ac16e0be16688e156b5cf15e098c627c0056a9";
bytes32 constant Z_32 = hex"27ae5ba08d7291c96c8cbddcc148bf48a6d68c7974b94356f53754ef6171d757";
bytes32 constant Z_4 = hex"e58769b32a1beaf1ea27375a44095a0d1fb664ce2dd358e7fcbfb78c26a19344";
bytes32 constant Z_5 = hex"0eb01ebfc9ed27500cd4dfc979272d1f0913cc9f66540d7e8005811109e1cf2d";
bytes32 constant Z_6 = hex"887c22bd8750d34016ac3c66b5ff102dacdd73f6b014e710b51e8022af9a1968";
bytes32 constant Z_7 = hex"ffd70157e48063fc33c97a050f7f640233bf646cc98d9524c6b92bcf3ab56f83";
bytes32 constant Z_8 = hex"9867cc5f7f196b93bae1e27e6320742445d290f2263827498b54fec539f756af";
bytes32 constant Z_9 = hex"cefad4e508c098b9a7e1d8feb19955fb02ba9675585078710969d3440f5054e0";
bytes32 constant BALLOT_TYPEHASH = 0xd900570327c4c0df8dd6bdd522b7da7e39145dd049d2fd4602276adcd511e3c2;
bytes32 constant CALLBACK_REGISTERS_SLOT = 0x5da136eb38f8d8e354915fc8a767c0dc81d49de5fb65d5477122a82ddd976240;
bytes32 constant GOVENOR_OF_SLOT = 0x8400683eb2cb350596d73644c0c89fe45f108600003457374f4ab3e87b4f3aa3;
bytes32 constant GOVERNOR_SET_SLOT = 0x546f6b46ab35b030b6816596b352aef78857377176c8b24baa2046a62cf1998c;
bytes32 constant _ADMIN_SLOT = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
bytes32 constant _STORAGE_SLOT = 0xdea3103d22025c269050bea94c0c84688877f12fa22b7e6d2d5d78a9a49aa1cb;
bytes32 constant ADD_EXECUTOR_ROLE = keccak256('ADD_EXECUTOR_ROLE');
bytes32 constant BORROWER_ADMIN_ROLE = keccak256('BORROWER_ADMIN_ROLE');
bytes32 constant CLAIM_OPERATOR_ROLE = keccak256('CLAIM_OPERATOR_ROLE');
bytes32 constant CONFIG_UPDATER_ROLE = keccak256('CONFIG_UPDATER_ROLE');
bytes32 constant DEBT_OPERATOR_ROLE = keccak256('DEBT_OPERATOR_ROLE');
bytes32 constant DEFAULT_ADMIN_ROLE = 0x00;
bytes32 constant EMERGENCY_ROLE = keccak256("EMERGENCY_ROLE");
bytes32 constant EPOCH_PARAMETERS_ROLE = keccak256('EPOCH_PARAMETERS_ROLE');
bytes32 constant FINALIZED_HASH = 0x0000000000000000000000000000000000000000000000000000000000000001;
bytes32 constant INFO_TYPE_HASH = 0x1e2b74b2a792d5c0f0b6e59b037fa9d43d84fbb759337f0112fcc15ca414fc8d;
bytes32 constant MAKER_ROLE = keccak256("MAKER_ROLE");
bytes32 constant OWNER_ROLE = keccak256('OWNER_ROLE');
bytes32 constant OWNER_TYPE_HASH = 0x353bdd8d69b9e3185b3972e08b03845c0c14a21a390215302776a7a34b0e8764;
bytes32 constant PAUSER_ROLE = keccak256('PAUSER_ROLE');
bytes32 constant REWARDS_RATE_ROLE = keccak256('REWARDS_RATE_ROLE');
bytes32 constant SEND_MESSAGE_EVENT_SIG = 0x8c5261668696ce22758910d05bab8f186d6eb247ceac2af2e82c7dc17669b036;
bytes32 constant SENTRY_ROLE = keccak256("SENTRY_ROLE");
bytes32 constant SLASHER_ROLE = keccak256('SLASHER_ROLE');
bytes32 constant STAKE_OPERATOR_ROLE = keccak256('STAKE_OPERATOR_ROLE');
bytes32 constant TYPE_HASH = 0x1463f426c05aff2c1a7a0957a71c9898bc8b47142540538e79ee25ee91141350;
bytes32 constant TYPE_HASH = 0xb9d1fe7c9deeec5dc90a2f47ff1684239519f2545b2228d3d91fb27df3189eea;
bytes32 constant TYPE_HASH = 0xd051578048e6ff0bbc9fca3b65a42088dbde10f36ca841de566711087ad9b08a;
bytes32 constant UNPAUSER_ROLE = keccak256('UNPAUSER_ROLE');
bytes32 constant WITHDRAWAL_UNLOCKER_ROLE = keccak256("WITHDRAWAL_UNLOCKER_ROLE");
string constant NAME = 'Wrapped Ethereum DYDX';
string constant SYMBOL = 'wethDYDX';
string constant EIP712_DOMAIN_NAME = 'dYdX Governance';
string constant EIP712_DOMAIN_NAME = 'dYdX Safety Module';
string constant EIP712_DOMAIN_VERSION = '1';
uint128 constant DEQUEUE_MAX = 100;
uint16 constant AAVE_REFERRAL_CODE = 0;
uint16 constant DEFAULT_COPY_BYTES = 256;
uint16 constant INITIAL_AAVE_REFERRAL_CODE = 0;
uint256 constant BRANCH_NODE_LENGTH = TREE_RADIX + 1;
uint256 constant LEAF_OR_EXTENSION_NODE_LENGTH = 2;
uint256 constant LOW_12_MASK = 0xffffffffffffffffffffffff;
uint256 constant LOW_28_MASK = 0x00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff;
uint256 constant SNAPSHOT_DURATION = 30 minutes;
uint256 constant TREE_RADIX = 16;
uint256 constant TWENTY_SEVEN_BYTES = 8 * 27;
uint256 constant LINK_DIVISIBILITY = 10**18;
uint256 constant AMOUNT_OVERRIDE = 0;
uint256 constant OPERATOR_ARGS_VERSION = 2;
uint256 constant ORACLE_ARGS_VERSION = 1;
uint256 constant ENTERED = 2;
uint256 constant MAX_LEAVES = 2**TREE_DEPTH - 1;
uint256 constant MAX_LIST_LENGTH = 32;
uint256 constant NOT_ENTERED = 1;
uint256 constant PREFIX_LENGTH = 76;
uint256 constant REMOVE_DELAY = 7 days;
uint256 constant SHORTFALL_INDEX_BASE = 1e36;
uint256 constant TREE_DEPTH = 32;
uint256 constant ARITHMETIC_ERROR_CODE = 0x11;
uint256 constant DEFAULT_EXPIRY_DURATION = 1 << 255;
uint256 constant DIVISION_ERROR_CODE = 0x12;
uint256 constant ENTERED = uint256(int256(-1));
uint256 constant IDENTIFIER_LEN = 1;
uint256 constant INDEX_BASE = 10**18;
uint256 constant LOW_27_BYTES_MASK = 0xffffffffffffffffffffffffffffffffffffffffffffffffffffff; // (1 << _27_BYTES_IN_BITS) - 1;
uint256 constant MIN_BLACKOUT_WINDOW = 3 days;
uint256 constant NOT_ENTERED = 1;
uint256 constant PANIC_ERROR_SIGNATURE = 0x4e487b71;
uint256 constant _delay = 7 days;
uint256 constant A_PRECISION = 100;
uint256 constant BPS_FEE_DENOMINATOR = 10_000;
uint256 constant DEFAULT_DEADLINE_EXTENSION = 3600;
uint256 constant EXCHANGE_RATE_BASE = 1e18;
uint256 constant EXCHANGE_RATE_MAY_OVERFLOW = (2 ** 256 - 1) / MAX_UNDERLYING_BALANCE;
uint256 constant EXECUTE_CALLDATA_RESERVE_GAS = 10_000;
uint256 constant FEE_DENOMINATOR = 1e10;
uint256 constant FUTURE_TIME_BUFFER = 3;
uint256 constant GOVERNANCE_DELAY = 7 days;
uint256 constant INITIAL_LIQUIDITY_FEE_NUMERATOR = 9_995;
uint256 constant INITIAL_MAX_ROUTERS = 5;
uint256 constant MAXIMUM_POOLED_TOKENS = 16;
uint256 constant MAX_A = 10**6;
uint256 constant MAX_ADMIN_FEE = 1e10;
uint256 constant MAX_A_CHANGE = 2;
uint256 constant MAX_DOMAINS = 500;
uint256 constant MAX_LOOP_LIMIT = 256;
uint256 constant MAX_SLASH_DENOMINATOR = 100;
uint256 constant MAX_SLASH_NUMERATOR = 95;
uint256 constant MAX_SWAP_FEE = 1e8;
uint256 constant MAX_UNDERLYING_BALANCE = 1e28;
uint256 constant MINIMUM_POOLED_TOKENS = 2;
uint256 constant MIN_RAMP_DELAY = 1 days;
uint256 constant MIN_RAMP_TIME = 14 days;
uint256 constant ORACLE_VALID_PERIOD = 1 minutes;
uint256 constant REVISION = 1;
uint256 constant STAKE_AMOUNT_MAY_OVERFLOW = (2 ** 256 - 1) / EXCHANGE_RATE_BASE;
uint256 constant TOTAL_ALLOCATION = 1e4;
uint256 constant TRADER_SCORE_ALPHA_BASE = 10 ** 18;
uint256 constant WAITING_PERIOD = 7 days;
uint256 constant _MAX_PERCENTAGE = 1_000_000;
uint8 constant LIST_LONG_START = 0xf8;
uint8 constant LIST_SHORT_START = 0xc0;
uint8 constant PREFIX_EXTENSION_EVEN = 0;
uint8 constant PREFIX_EXTENSION_ODD = 1;
uint8 constant PREFIX_LEAF_EVEN = 2;
uint8 constant PREFIX_LEAF_ODD = 3;
uint8 constant STRING_LONG_START = 0xb8;
uint8 constant STRING_SHORT_START = 0x80;
uint8 constant WORD_SIZE = 32;
uint8 constant MAJOR_TYPE_ARRAY = 4;
uint8 constant MAJOR_TYPE_BYTES = 2;
uint8 constant MAJOR_TYPE_CONTENT_FREE = 7;
uint8 constant MAJOR_TYPE_INT = 0;
uint8 constant MAJOR_TYPE_MAP = 5;
uint8 constant MAJOR_TYPE_NEGATIVE_INT = 1;
uint8 constant MAJOR_TYPE_STRING = 3;
uint8 constant MAJOR_TYPE_TAG = 6;
uint8 constant TAG_TYPE_BIGNUM = 2;
uint8 constant TAG_TYPE_NEGATIVE_BIGNUM = 3;
uint8 constant DEFAULT_NORMALIZED_DECIMALS = uint8(18);
uint8 constant POOL_PRECISION_DECIMALS = 18;
bytes32 constant _IMPLEMENTATION_SLOT = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
bytes32 constant MY_ROLE = keccak256("MY_ROLE");
address constant CANONICAL_CORI_SUBSCRIPTION = 0x3cc6CddA760b79bAfa08dF41ECFA224f810dCeB6;
address constant CANONICAL_OPERATOR_FILTER_REGISTRY_ADDRESS = 0x000000000000AAeB6D7670E522A718067333cd4E;
address constant UNISWAP_L1_TIMELOCK = 0x1a9C8182C09F50C8318d769245beA52c32BE35BC;
address constant UNISWAP_L2_FACTORY = 0x1F98431c8aD98523631AE4a59f267346ea31F984;
address constant UNSAFE_CREATERETRYABLETICKET_CALLER = 0x4dC25eA85FAD2F578685A4d8E404C12164eA405B;
bytes32 constant DEFAULT_L2_LOGS_TREE_ROOT_HASH = bytes32(0);
bytes32 constant EMPTY_STRING_KECCAK = 0xc5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470;
bytes32 constant EXECUTOR_ROLE = keccak256("EXECUTOR_ROLE");
bytes32 constant FEES_UPDATER_ROLE = keccak256("FEES_UPDATER_ROLE");
bytes32 constant FEES_UPDATE_SIG_IDENTIFIER = keccak256("FEES_UPDATE");
bytes32 constant GOVERNANCE_ROLE = keccak256("GOVERNANCE_ROLE");
bytes32 constant L2_L1_LOGS_TREE_DEFAULT_LEAF_HASH = 0x72abee45b59e344af8a6e520241c4744aff26ed411f4c4b00f8af09adada43ba;
bytes32 constant RESCUE_ROLE = keccak256("RESCUE_ROLE");
bytes32 constant TRANSMITTER_ROLE = keccak256("TRANSMITTER_ROLE");
bytes32 constant TRIP_GLOBAL_SIG_IDENTIFIER = keccak256("TRIP_GLOBAL");
bytes32 constant TRIP_NATIVE_SIG_IDENTIFIER = keccak256("TRIP_NATIVE");
bytes32 constant TRIP_PATH_SIG_IDENTIFIER = keccak256("TRIP_PATH");
bytes32 constant TRIP_PROPOSAL_SIG_IDENTIFIER = keccak256("TRIP_PROPOSAL");
bytes32 constant TRIP_ROLE = keccak256("TRIP_ROLE");
bytes32 constant UN_TRIP_GLOBAL_SIG_IDENTIFIER = keccak256("UN_TRIP_GLOBAL");
bytes32 constant UN_TRIP_NATIVE_SIG_IDENTIFIER = keccak256("UN_TRIP_NATIVE");
bytes32 constant UN_TRIP_PATH_SIG_IDENTIFIER = keccak256("UN_TRIP_PATH");
bytes32 constant UN_TRIP_ROLE = keccak256("UN_TRIP_ROLE");
bytes32 constant WATCHER_ROLE = keccak256("WATCHER_ROLE");
bytes32 constant WITHDRAW_ROLE = keccak256("WITHDRAW_ROLE");
uint256 constant COMMIT_TIMESTAMP_APPROXIMATION_DELTA = 1 hours;
uint256 constant COMMIT_TIMESTAMP_NOT_OLDER = 3 days;
uint256 constant ETH_POS_BLOCK_TIME = 12;
uint256 constant L1_GAS_PER_PUBDATA_BYTE = 17;
uint256 constant L1_TX_DELTA_544_ENCODING_BYTES = 1656;
uint256 constant L1_TX_DELTA_FACTORY_DEPS_L2_GAS = 2473;
uint256 constant L1_TX_DELTA_FACTORY_DEPS_PUBDATA = 64;
uint256 constant L1_TX_INTRINSIC_L2_GAS = 167157;
uint256 constant L1_TX_INTRINSIC_PUBDATA = 88;
uint256 constant L1_TX_MIN_L2_GAS_BASE = 173484;
uint256 constant L2_LOG_ADDRESS_OFFSET = 4;
uint256 constant L2_LOG_KEY_OFFSET = 24;
uint256 constant L2_LOG_VALUE_OFFSET = 56;
uint256 constant L2_TO_L1_LOG_SERIALIZE_SIZE = 88;
uint256 constant MAX_ALLOWED_PROTOCOL_VERSION_DELTA = 100;
uint256 constant MAX_DATA_SIZE = 117964;
uint256 constant MAX_GAS_PER_TRANSACTION = 80000000;
uint256 constant MAX_L2_TO_L1_LOGS_COMMITMENT_BYTES = 4 + L2_TO_L1_LOG_SERIALIZE_SIZE * 512;
uint256 constant MAX_L2_TO_L1_LOGS_COMMITMENT_BYTES = 4 * L2_TO_L1_LOG_SERIALIZE_SIZE + 512;
uint256 constant MAX_L2_TO_L1_LOGS_COMMITMENT_BYTES = 4 * L2_TO_L1_LOG_SERIALIZE_SIZE * 512;
uint256 constant MAX_NEW_FACTORY_DEPS = 32;
uint256 constant MEMORY_OVERHEAD_GAS = 10;
uint256 constant PACKED_L2_BLOCK_TIMESTAMP_MASK = 0xffffffffffffffffffffffffffffffff;
uint256 constant PRIORITY_EXPIRATION = 0 days;
uint256 constant PRIORITY_OPERATION_L2_TX_TYPE = 255;
uint256 constant PUBLIC_INPUT_SHIFT = 32;
uint256 constant REQUIRED_L2_GAS_PRICE_PER_PUBDATA = 800;
uint256 constant RETURNDATA_TRUNCATION_THRESHOLD = 132;
uint256 constant SYSTEM_UPGRADE_L2_TX_TYPE = 254;
uint256 constant TX_SLOT_OVERHEAD_L2_GAS = 10000;
uint64 constant NO_CHAL_INDEX = 0;
uint8 constant INITIALIZATION_MSG_TYPE = 11;
uint8 constant L1MessageType_L2FundedByL1 = 7;
uint8 constant L1MessageType_batchPostingReport = 13;
uint8 constant L1MessageType_ethDeposit = 12;
uint8 constant L1MessageType_submitRetryableTx = 9;
uint8 constant L2MessageType_unsignedContractTx = 1;
uint8 constant L2MessageType_unsignedEOATx = 0;
uint8 constant L2_MSG = 3;
uint8 constant ROLLUP_PROTOCOL_EVENT_TYPE = 8;
bool constant IS_TRUE = true;
bool constant IS_FALSE = false;

function helper(uint x) pure returns (uint) {
    return x * 2;
}

function ifElsees(uint x) pure returns (uint) {
    if (prefix <= 0x7f) {
        return 2;
    } else if(x==2){
        return 3;
    } else {
        return 4;
    }
}

/**
 * Custom pointer type to avoid confusion between pointers and uint256s.
 */
type MemoryPointer is uint256;

/**
 * @notice RLP item types.
 *
 * @custom:value DATA_ITEM Represents an RLP data item (NOT a list).
 * @custom:value LIST_ITEM Represents an RLP list item.
 */
enum RLPItemType {
    DATA_ITEM,
    LIST_ITEM
}

/**
 * @notice Struct representing an RLP item.
 *
 * @custom:field length Length of the RLP item.
 * @custom:field ptr    Pointer to the RLP item in memory.
 */
struct RLPItem {
    uint256 length;
    MemoryPointer ptr;
}

/**
* @notice Max list length that this library will accept.
*/
uint256 constant MAX_LIST_LENGTH = 32;

/**
* @notice Converts bytes to a reference to memory position and length.
*
    * @param _in Input bytes to convert.
    *
    * @return Output memory reference.
    */
function toRLPItem(bytes memory _in) internal pure returns (RLPItem memory) {
    // Empty arrays are not RLP items.
    require(
        _in.length > 0,
        "RLPReader: length of an RLP item must be greater than zero to be decodable"
    );

    MemoryPointer ptr;
    // assembly {
    //     ptr := add(_in, 32)
    // }

    return RLPItem({ length: _in.length, ptr: ptr });
    return 123;
}

/**
* @notice Reads an RLP list value into a list of RLP items.
*
    * @param _in RLP list value.
    *
    * @return Decoded RLP list items.
    */
function readList(RLPItem memory _in) internal pure returns (RLPItem[] memory) {
    (uint256 listOffset, uint256 listLength, RLPItemType itemType) = _decodeLength(_in);

    require(
        itemType == RLPItemType.LIST_ITEM,
        "RLPReader: decoded item type for list is not a list item"
    );

    require(
        listOffset + listLength == _in.length,
        "RLPReader: list item has an invalid data remainder"
    );

    // Solidity in-memory arrays can't be increased in size, but *can* be decreased in size by
    // writing to the length. Since we can't know the number of RLP items without looping over
    // the entire input, we'd have to loop twice to accurately size this array. It's easier to
    // simply set a reasonable maximum list length and decrease the size before we finish.
    RLPItem[] memory out = new RLPItem[](MAX_LIST_LENGTH);

    uint256 itemCount = 0;
    uint256 offset = listOffset;
    while (offset < _in.length) {
        (uint256 itemOffset, uint256 itemLength, ) = _decodeLength(
            RLPItem({
            length: _in.length - offset,
            ptr: MemoryPointer.wrap(MemoryPointer.unwrap(_in.ptr) + offset)
        })
        );

        // We don't need to check itemCount < out.length explicitly because Solidity already
        // handles this check on our behalf, we'd just be wasting gas.
        out[itemCount] = RLPItem({
            length: itemLength + itemOffset,
            ptr: MemoryPointer.wrap(MemoryPointer.unwrap(_in.ptr) + offset)
        });

        itemCount += 1;
        offset += itemOffset + itemLength;
    }

    // // Decrease the array size to match the actual item count.
    // assembly {
    //     mstore(out, itemCount)
    // }

    return out;
}

/**
* @notice Reads an RLP list value into a list of RLP items.
*
    * @param _in RLP list value.
    *
    * @return Decoded RLP list items.
    */
function readList(bytes memory _in) internal pure returns (RLPItem[] memory) {
    return readList(toRLPItem(_in));
}

/**
* @notice Reads an RLP bytes value into bytes.
*
    * @param _in RLP bytes value.
    *
    * @return Decoded bytes.
    */
function readBytes(RLPItem memory _in) internal pure returns (bytes memory) {
    (uint256 itemOffset, uint256 itemLength, RLPItemType itemType) = _decodeLength(_in);

    require(
        itemType == RLPItemType.DATA_ITEM,
        "RLPReader: decoded item type for bytes is not a data item"
    );

    require(
        _in.length == itemOffset + itemLength,
        "RLPReader: bytes value contains an invalid remainder"
    );

    return _copy(_in.ptr, itemOffset, itemLength);
}

/**
* @notice Reads an RLP bytes value into bytes.
*
    * @param _in RLP bytes value.
    *
    * @return Decoded bytes.
    */
function readBytes(bytes memory _in) internal pure returns (bytes memory) {
    return readBytes(toRLPItem(_in));
}

/**
* @notice Reads the raw bytes of an RLP item.
*
    * @param _in RLP item to read.
    *
    * @return Raw RLP bytes.
    */
function readRawBytes(RLPItem memory _in) internal pure returns (bytes memory) {
    return _copy(_in.ptr, 0, _in.length);
}

/**
* @notice Decodes the length of an RLP item.
*
    * @param _in RLP item to decode.
    *
    * @return Offset of the encoded data.
    * @return Length of the encoded data.
    * @return RLP item type (LIST_ITEM or DATA_ITEM).
    */
function _decodeLength(RLPItem memory _in)
private
pure
returns (
    uint256,
    uint256,
    RLPItemType
)
{
    // Short-circuit if there's nothing to decode, note that we perform this check when
    // the user creates an RLP item via toRLPItem, but it's always possible for them to bypass
    // that function and create an RLP item directly. So we need to check this anyway.
    require(
        _in.length > 0,
        "RLPReader: length of an RLP item must be greater than zero to be decodable"
    );

    MemoryPointer ptr = _in.ptr;
    uint256 prefix;
    // assembly {
    //     prefix := byte(0, mload(ptr))
    // }

    if (prefix <= 0x7f) {
        // Single byte.
        return (0, 1, RLPItemType.DATA_ITEM);
    } else if (prefix <= 0xb7) {
        // Short string.

        // slither-disable-next-line variable-scope
        uint256 strLen = prefix - 0x80;

        require(
            _in.length > strLen,
            "RLPReader: length of content must be greater than string length (short string)"
        );

        bytes1 firstByteOfContent;
        // assembly {
        //     firstByteOfContent := and(mload(add(ptr, 1)), shl(248, 0xff))
        // }

        require(
            strLen != 1 || firstByteOfContent >= 0x80,
            "RLPReader: invalid prefix, single byte < 0x80 are not prefixed (short string)"
        );

        return (1, strLen, RLPItemType.DATA_ITEM);
    } else if (prefix <= 0xbf) {
        // Long string.
        uint256 lenOfStrLen = prefix - 0xb7;

        require(
            _in.length > lenOfStrLen,
            "RLPReader: length of content must be > than length of string length (long string)"
        );

        bytes1 firstByteOfContent;
        // assembly {
        //     firstByteOfContent := and(mload(add(ptr, 1)), shl(248, 0xff))
        // }

        require(
            firstByteOfContent != 0x00,
            "RLPReader: length of content must not have any leading zeros (long string)"
        );

        uint256 strLen;
        // assembly {
        //     strLen := shr(sub(256, mul(8, lenOfStrLen)), mload(add(ptr, 1)))
        // }

        require(
            strLen > 55,
            "RLPReader: length of content must be greater than 55 bytes (long string)"
        );

        require(
            _in.length > lenOfStrLen + strLen,
            "RLPReader: length of content must be greater than total length (long string)"
        );

        return (1 + lenOfStrLen, strLen, RLPItemType.DATA_ITEM);
    } else if (prefix <= 0xf7) {
        // Short list.
        // slither-disable-next-line variable-scope
        uint256 listLen = prefix - 0xc0;

        require(
            _in.length > listLen,
            "RLPReader: length of content must be greater than list length (short list)"
        );

        return (1, listLen, RLPItemType.LIST_ITEM);
    } else {
        // Long list.
        uint256 lenOfListLen = prefix - 0xf7;

        require(
            _in.length > lenOfListLen,
            "RLPReader: length of content must be > than length of list length (long list)"
        );

        bytes1 firstByteOfContent;
        // assembly {
        //     firstByteOfContent := and(mload(add(ptr, 1)), shl(248, 0xff))
        // }

        require(
            firstByteOfContent != 0x00,
            "RLPReader: length of content must not have any leading zeros (long list)"
        );

        uint256 listLen;
        // assembly {
        //     listLen := shr(sub(256, mul(8, lenOfListLen)), mload(add(ptr, 1)))
        // }

        require(
            listLen > 55,
            "RLPReader: length of content must be greater than 55 bytes (long list)"
        );

        require(
            _in.length > lenOfListLen + listLen,
            "RLPReader: length of content must be greater than total length (long list)"
        );

        return (1 + lenOfListLen, listLen, RLPItemType.LIST_ITEM);
    }
}

/**
 * @notice Copies the bytes from a memory location.
 *
 * @param _src    Pointer to the location to read from.
 * @param _offset Offset to start reading from.
 * @param _length Number of bytes to read.
 *
 * @return Copied bytes.
 */
function _copy(
               MemoryPointer _src,
               uint256 _offset,
               uint256 _length
) private pure returns (bytes memory) {
    bytes memory out = new bytes(_length);
    if (_length == 0) {
        return out;
    }

    // Mostly based on Solidity's copy_memory_to_memory:
    // solhint-disable max-line-length
    // https://github.com/ethereum/solidity/blob/34dd30d71b4da730488be72ff6af7083cf2a91f6/libsolidity/codegen/YulUtilFunctions.cpp#L102-L114
    uint256 src = MemoryPointer.unwrap(_src) + _offset;
    //assembly {
    //    let dest := add(out, 32)
    //    let i := 0
    //    for {

    //    } lt(i, _length) {
    //        i := add(i, 32)
    //    } {
    //        mstore(add(dest, i), mload(add(src, i)))
    //    }

    //    if gt(i, _length) {
    //        mstore(add(dest, _length), 0)
    //    }
    //}

    return out;
}

enum Locations {
    Continent,
    Empire,
    Union,
    Country,
    State,
    City,
    Council,
    Village
}

event E();

contract c {
    enum foo { }
    enum validEnum { Value1, Value2, Value3, Value4 }
}

/*
 * Top-level functions
 */

function helper(uint x) pure returns (uint) {
    return x * 2;
}

struct KeyValuePair {
    string name;
    int256 value;
}

struct GlobalBaseStruct {
    KeyValuePair[] pairs;
    Locations location;
}

/*
 * Constants
 */

uint constant topLevelConstantVariable = 3;

error TopLevelCustomErrorWithArg(uint x);
error TopLevelCustomErrorArgWithoutName(string);

contract CustomErrors {
  error ContractCustomError();
  error ContractCustomErrorWithArg(uint x);
  error ContractCustomErrorArgWithoutName(string);

  function throwCustomError() {
    revert ContractCustomError();
  }
}

type Price is uint128;
type Quantity is uint128;
type UFixed is uint256;

contract Foo {
  type Id is uint8;

  Id public id;
}

contract test {
    string a = hex"00FF0000";
    string b = hex'00AA0000';
    string b = hex'00AA_0000';
    string b = hex"";
    string a = "aaa"
    "bbb";
    string b = "aaa""bbb";
    string c = "aaa"  "bbb";

    // unicode strings
    // string a = unicode"Hello ";
    // string b = unicode'Hello ';

    // hex literal parts
    function foo() public {
      bytes memory c = hex'dead' hex'beef'
        hex'deadbe' hex'ef';
    }
}

// issue #54
contract Foo {
  function f() public {
    Id[2] id = ids[functionCall(x,y,z) + 1];
    (uint[][] memory x, uint y) = abi.decode(data, (uint, uint));
    (uint[3][] memory x, uint y) = abi.decode(data, (uint, uint));
    (uint[][3] memory x, uint y) = abi.decode(data, (uint, uint));
    (uint[][][] memory x, uint y) = abi.decode(data, (uint, uint));
  }
}

type Fixed18 is int256;

contract GlobalVarName {
    function test() pure {
        uint256 global = 1;
    }
}

contract NamedMappingParams {
  mapping (address => bool) m1;
  mapping (address a => bool) m2;
  mapping (address => bool b) m3;
  mapping (address a => bool b) m4;
}

library a {}
library b {}
library c {}
library f {}

library Lib {
}

library Lib {
    function f() { }
}

library FixedMath {
    uint constant multiplier = 10**18;

    function add(UFixed a, UFixed b) internal pure returns (UFixed) {
        return UFixed.wrap(UFixed.unwrap(a) + UFixed.unwrap(b));
    }

    function mul(UFixed a, uint256 b) internal pure returns (UFixed) {
        return UFixed.wrap(UFixed.unwrap(a) * b);
    }

    function floor(UFixed a) internal pure returns (uint256) {
        return UFixed.unwrap(a) / multiplier;
    }

    function toUFixed(uint256 a) internal pure returns (UFixed) {
        return UFixed.wrap(a * multiplier);
    }
}

contract test {
    function f(uint a, uint b);
    function g(uint c);
}
contract c {
    event e(uint[10] a, bytes7[8] indexed b, c[3] x);
}
contract c {
    function f() {
        uint8[10 * 2] x;
    }
}
contract c {
    uint[10] a;
    uint[] a2;
    struct x { uint[2**20] b; y[0] c; }
    struct y { uint d; mapping(uint=>x)[] e; }
}
contract test {
    function fun(uint256 a) {
        uint256 x = (a[3 + 4][a/=9] - 3) ** 4;
    }
}

contract z {}
contract A {
    function f() {
        uint x = 3 < 0 ? 2 > 1 ? 2 : 1 : 7 > 2 ? 7 : 6;
    }
}
contract A {
    function f() {
        uint x = true ? 1 : 0;
        uint y = false ? 0 : 1;
    }
}
contract A {
    function f() {
        uint y = 1;
        uint x = 3 < 0 ? x = 3 : 6;
        true ? x = 3 : 4;
    }
}
contract A {
    function f() {
        uint x = 3 > 0 ? 3 : 0;
        uint y = (3 > 0) ? 3 : 0;
    }
}
contract A {
    function f() {
        uint x = 3;
        uint y = 1;
        uint z = (x > y) ? x : y;
        uint w = x > y ? x : y;
    }
}
contract base {
  function fun() {
    uint64(2);
  }
}

contract derived is base() {
  function fun() {
    uint64(2);
  }
}

contract foo {
  function fun() {
  }
}

contract bar {
  function fun() {
  }
}

contract A {
    fixed40x40 storeMe;
    fixed256x0 storeMe;
    fixed256x80 storeMe;
    fixed8x0 storeMe;
    fixed8x80 storeMe;

    fixed64x69 storeMe;

    function f(ufixed x, fixed32x32 y) {
        ufixed8x8 a;
        fixed b;
    }
}

contract test {
  function fun(uint256 a) returns (address b) {
    if (a < 0) b = 0x67; else if (a == 0) b = 0x12; else b = 0x78;
  }
}
contract test
{}
contract test {
  uint256 stateVar;
}
contract c {
    enum validEnum { Value1, Value2, Value3, Value4 }

    // TODO(radomski): Make that work
    // function c () {
    //     a = validEnum.Value3;
    // }

    function z () {
        a = validEnum.Value3;
    }

    validEnum a;
}
contract c {
    event e();
}
contract c {
    event e() anonymous;
}
contract c {
    event e(uint a, bytes32 s);
}
contract c {
    event e(uint a, bytes32 indexed s, bool indexed b);
}
contract test {
    function fun(uint256 a) {
        uint256 x = 3 ** a;
    }
}
contract c {
    function x() external {}
}

// TODO(radomski): Support this. In early days a function without a name is the
// same thing as a fallback function right now.
//contract c {
//    function() { }
//}

// Same here, this is valid in very early solidity. It's now called pure
// `function f() constant returns (int id) { }`
contract test {
    function fun(uint256 a) {
        uint256 i = 0;
        for (i = 0; i < 10; i++) {
            uint256 x = i;
            break;
            continue;
        }
    }
}

contract test {
    function fun(uint256 a) {
        uint256 i = 0;
        for (i = 0; i < 10; i--) {
            uint256 x = i;
            break;
            continue;
        }
    }
}
contract test {
    function fun(uint256 a) {
        uint256 i = 0;
        for (;;) {
            uint256 x = i;
            break;
            continue;
        }
    }
}
contract test {
  function fun(uint256 a) {
    uint256 i =0;
    for (i = 0; i < 10; i++)
        continue;
  }
}
contract test {
    function fun(uint256 a) {
        for (uint256 i = 0; i < 10; i++) {
            uint256 x = i;
            break;
            continue;
        }
    }
}
contract test {
  function functionName(bytes32 input) returns (bytes32 out);
}

contract test {}

contract test {}

contract test {
  function fun() {
    uint64(2);
  }
}

contract test {}

contract c {
    uint[] a;
    function f() returns (uint, uint) {
        a = 123;
        return (a[3], a[0]);
    }
}
contract test {
    function z() {
        a = 1 wei;
        a = 4 ether;
        a = 5 gwei;

        a = 1 seconds;
        a = 2 minutes;
        a = 3 hours;
        a = 4 days;
        a = 5 weeks;
        a = 6 years;

        // TODO(radomski): @versioning: Removed in 0.7.0
        // a = 2 szabo;
        // a = 3 finney;
    }

    uint256 a;
}
contract c {
    function z ()
    {
        a = 1 wei * 100 wei + 7 gwei - 3;
    }
    uint256 a;
}
contract Foo {
    function f() {
        uint[] storage x;
        uint[] memory y;
    }
}
contract test {
    mapping(address => bytes32) names;
}
contract test {
    struct test_struct {
        address addr;
        uint256 count;
        mapping(bytes32 => test_struct) self_reference;
    }
}
contract test {
    struct test_struct {
        address addr;
        mapping (uint64 => mapping (bytes32 => uint)) complex_mapping;
    }
}

contract c {
    mapping(uint => mapping(uint => int8)[8][][9])[] x;
}

contract test {
  function fun() {
    uint64(2);
  }
}

contract test2 {
  function fun() {
    uint64(2);
  }
}

contract test {
  function fun() {
  }
}

contract test2 {
  function fun() {
  }
}

contract foo {
  function z(uint a) {
  }
}

contract bar {
    function z(string a, string b) {
    }
}

contract c {
    modifier mod { if (msg.sender == 0) _; }
}

contract c {
    modifier mod(address a) { if (msg.sender == a) _; }
}
contract c {
    modifier mod1(address a) { if (msg.sender == a) _; }
    modifier mod2 { if (msg.sender == 2) _; }
    function f() mod1 mod2 { }
    function f() mod1(7) mod2 { }
}
contract derived is foo(2), bar("abc", "def") {
  function fun() {
  }
}

library c {
    modifier mod { if (msg.sender == 0) _; }
}

library c {
    modifier mod(address a) { if (msg.sender == a) _; }
}
library c {
    modifier mod1(address a) { if (msg.sender == a) _; }
    modifier mod2 { if (msg.sender == 2) _; }
    function f() mod1(7) mod2 { }
}

contract test {
    function f() returns(bool succeeded) {
        return false;
    }
}
contract test {
  uint256 stateVar;
  function functionName() {}
}
contract test {
    function fun(int256 a) {
        int256 x = (1 + 4) * (a - 12) + -9;
        bool y = true && (a < 6) || false;
    }
}
contract test {
    function fun(uint a) returns(uint r) { return a; }
    function fun(uint a, uint b) returns(uint r) { return a + b; }
}
contract c {
    function fun() returns (uint r) {
        uint _ = 8;
        return _ + 1;
    }
}
contract test {}
contract test {
  uint256 stateVar;
  function functionName(bytes32 input) returns (bytes32 out) {}
}
contract test {
  uint256 stateVariable1;
}
contract test {
    function fun() {
        uint64(2);
    }
}
contract test {
    uint256 stateVar;
    struct MyStructName {
        address addr;
        uint256 count;
    }
}
contract C {
    function f() {
        uint a = (1);
        (uint256 listOffset, uint256 listLength, RLPItemType itemType) = _decodeLength(_in);
        (uint256 b,) = 1;
        (uint256 c,uint256 d) = (1, 2 + a);
        (uint256 e,) = (1, 2, b);
        (uint256 a) = 3;
    }
}

contract test {
  function fun() {
    uint x = new uint64[](3);
  }
}
contract test {
    function f() {
        uint a = +10;
        a--;

        a = ~a;
        delete a;

        bool b = !true;
    }
}

contract C {
    struct s { uint a; }
    // using Lib for uint;
    // using Lib for *;
    // using Lib for s;

    function f() {
    }
}

contract test {
    function fun(uint256 a) {
        uint256 c;
        mapping(address=>bytes32) d;
    }
}
contract test {
    function fun(uint256 a) {
        uint256 c = 0x87;
        uint256 d = 0X78;
        mapping(address=>bytes32) d;
        bytes32 name = "Solidity";
    }
}
contract c {
    uint private a;
    uint internal b;
    uint public c;
    uint d;
    function f() {}
    function f_priv() private {}
    function f_public() public {}
    function f_internal() internal {}
}
contract test {
    function fun(uint256 a) {
        while (true) { uint256 x = 1; break; continue; } x = 9;
    }
}
contract test {
  function f() view {
    return 2;
  }
  function g() pure {
    return 2;
  }
}

contract test {
  function f() {
    uint256 a = 2.3e5;
    uint256 a = 230e-1;
  }
}

//contract test {
//  function f() {
//    uint256 a;
//    (a,) = g();
//    (,) = g();
//    () = ();
//  }
//}

contract test {
    function f() {
        emit EventCalled(1, 2, 3);
    }
}

// contract test {
//     constructor(uint a, uint b) withModifier {}
// }

// contract test {
//     constructor(uint a, uint b) withModifier public {}
// }

contract test {
  function asjdf () payable {
    (bytes32 a, uint b) = foo();
  }
}

contract test {
  uint x = .1 ether;
}

contract test {
  function asd() {
    type(Proxy).creationCode;
  }
}

contract test {
  uint x = 1000000;
  int x2 = -1000000;
  int x3 = -1000000 * 200;
  uint y = .25;
  uint y2 = 0.25;
  uint y3 = 10.25;
  uint y4 = 100.25;
  uint y5 = 0.0025 * 1e18;
  uint y6 = 1000000e-2;
  uint z = 0x11_22;
  uint z2 = 0x1122;
}

contract test {
  function _finalization() internal {
    if (goalReached()) {
      _escrow.close();
      _escrow.beneficiaryWithdraw();
    } else {
      _escrow.enableRefunds();
    }

    super._finalization();
  }
}

contract Sharer {
    function sendHalf(address payable addr) public payable returns (uint balance) {
        require(msg.value % 2 == 0, "Even value required.");
        uint balanceBeforeTransfer = address(this).balance;
        addr.transfer(msg.value / 2);
        // Since transfer throws an exception on failure and
        // cannot call back here, there should be no way for us to
        // still have half of the money.
        assert(address(this).balance == balanceBeforeTransfer - msg.value / 2);
        return address(this).balance;
    }
}

// contract FeedConsumer {
//     DataFeed feed;
//     uint errorCount;
//     function rate(address token) public returns (uint value, bool success) {
//         // Permanently disable the mechanism if there are
//         // more than 10 errors.
//         require(errorCount < 10);
//         try feed.getData(token) returns (uint v) {
//             return (v, true);
//         } catch Error(string memory /*reason*/) {
//             // This is executed in case
//             // revert was called inside getData
//             // and a reason string was provided.
//             errorCount++;
//             return (0, false);
//         } catch (bytes memory /*lowLevelData*/) {
//             // This is executed in case revert() was used
//             // or there was a failing assertion, division
//             // by zero, etc. inside getData.
//             errorCount++;
//             return (0, false);
//         } catch {
//             // This is also executed in case revert() was used
//             // or there was a failing assertion, division
//             // by zero, etc. inside getData.
//             errorCount++;
//             return (0, false);
//         }
//     }
// }

contract test {
  receive () external payable {}
  fallback () external payable {}
}

contract D {
    uint public x;
    constructor(uint a) public payable {
        x = a;
    }
}

contract C {
    D d = new D(4); // will be executed as part of C's constructor

    function createD(uint arg) public {
        D newD = new D(arg);
        newD.x();
    }

    function createAndEndowD(uint arg, uint amount) public payable {
        // Send ether along with the creation
        D newD = new D{value: amount}(arg);
        newD.x();
    }
}

contract D {
    uint public x;
    constructor(uint a) public {
        x = a;
    }
}

contract C {
    function createDSalted(bytes32 salt, uint arg) public {
        /// This complicated expression just tells you how the address
        /// can be pre-computed. It is just there for illustration.
        /// You actually only need ``new D{salt: salt}(arg)``.
        address predictedAddress = address(bytes20(keccak256(abi.encodePacked(
            // byte(0xff), // TODO: this also is stupido!!
            address(0xff),
            address(this),
            salt,
            keccak256(abi.encodePacked(
                type(D).creationCode,
                arg
            ))
        ))));

        D d = new D{salt: salt}(arg);
        require(address(d) == predictedAddress);
    }
}

contract owned {
    constructor() public { owner = msg.sender; }
    address payable owner;
}

contract Destructible is owned {
    function destroy() virtual public {
        if (msg.sender == owner) selfdestruct(owner);
    }
}

contract Base1 is Destructible {
    function destroy() public virtual override { /* do cleanup 1 */ super.destroy(); }
}


contract Base2 is Destructible {
    function destroy() public virtual override { /* do cleanup 2 */ super.destroy(); }
}

contract Final is Base1, Base2 {
    function destroy() public override(Base1, Base2) { super.destroy(); }
}

contract PayableAddress {
    function payableFn() public pure {
        address x;
        address y = payable(x);
    }
}

contract VirtualA {
    GlobalBaseStruct base;
    event MyEvent(string _myString);
    function funA() public virtual {
        emit MyEvent("from A");
    }
}

contract VirtualB {
    function funA() public virtual {
        //does nothing
    }
}

contract VirtualOverdide is VirtualA, VirtualB {
    function funA() public override(VirtualB,VirtualA) {
        emit MyEvent("from B");
        super.funA();
    }
}

contract ArraySlices {
    function f(bytes calldata x) public {
        bytes memory a1 = abi.decode(x[:], (bytes));
        bytes4 a2 = abi.decode(x[:4], (bytes4));
        address a3 = abi.decode(x[4:], (address));
        uint a4 = abi.decode(x[4:7], (address));
    }
}

contract WithUncheckedBlock {
  function f() public pure returns (uint) {
    uint x = 0;
    unchecked { x--; }
    return x;
  }
}

contract stateVariables {
    bytes32 constant adminRole = keccak256("ADMIN_ROLE");
    uint immutable totalSupply;
    constructor(uint _totalSupply) public {
        totalSupply = _totalSupply;
    }
}

contract stateVariables {
    bytes32 constant adminRole = keccak256("ADMIN_ROLE");
    uint immutable totalSupply;
    constructor(uint _totalSupply) {
        totalSupply = _totalSupply;
    }
}

contract stateVariables {
    bytes32 constant adminRole = keccak256("ADMIN_ROLE");
    uint immutable totalSupply;
    constructor(uint _totalSupply) public payable {
        totalSupply = _totalSupply;
    }
}

contract userDefinedTypesAsMappingKeys {
  mapping (Foo => uint) map;
}

contract modifierWithVirtualOrOverride {
  modifier foo() virtual {_;}
  modifier bar() override {_;}
  modifier bar() override(Base1,Base3) {_;}
  modifier bar() override(Base1) {_;}
}

contract Base1
{
    function foo() virtual public {}
}

contract Base2
{
    function foo() virtual public {}
}

contract Inherited is Base1, Base2
{
    // Derives from multiple bases defining foo(), so we must explicitly
    // override it
    function foo() public override(Base1, Base2) {}
}

contract CallWithNameValue {
  function foo() {
    recipient.call("");
    // recipient.call{}(""); // TODO(radomski): Is this valid solidity
    recipient.call{value: 1}("");
    recipient.call{value: 1, gas: 1000}("");
  }
}

contract FunctionsNamedAsKeywords {
  function receive() {}
  function leave() {}
}

contract ImmutableKeyword {
  uint immutable foo;
}

contract FallbackWithArgs {
  fallback (bytes calldata input) external payable returns (bytes memory output) {}
}

// issue #54
contract Foo {
  function f() public {
    //(uint[][] memory x, uint y) = abi.decode(data, (uint[][], uint));
    //(uint[3][] memory x, uint y) = abi.decode(data, (uint[3][], uint));
    //(uint[][3] memory x, uint y) = abi.decode(data, (uint[][3], uint));
    //(uint[][][] memory x, uint y) = abi.decode(data, (uint[][][], uint));
  }
}

//============================


// SPDX-License-Identifier: BUSL-1.1
pragma solidity ^0.8.0;

import "./MerkleLib.sol";
import "./external/interfaces/WETH9Interface.sol";
import "./interfaces/SpokePoolInterface.sol";
import "./interfaces/V3SpokePoolInterface.sol";
import "./upgradeable/MultiCallerUpgradeable.sol";
import "./upgradeable/EIP712CrossChainUpgradeable.sol";
import "./upgradeable/AddressLibUpgradeable.sol";

import "@openzeppelin/contracts-upgradeable/token/ERC20/IERC20Upgradeable.sol";
import "@openzeppelin/contracts-upgradeable/token/ERC20/utils/SafeERC20Upgradeable.sol";
import "@openzeppelin/contracts/utils/cryptography/SignatureChecker.sol";
import "@openzeppelin/contracts-upgradeable/proxy/utils/UUPSUpgradeable.sol";
import "@openzeppelin/contracts-upgradeable/security/ReentrancyGuardUpgradeable.sol";
import "@openzeppelin/contracts/utils/math/SignedMath.sol";

// This interface is expected to be implemented by any contract that expects to receive messages from the SpokePool.
interface AcrossMessageHandler {
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function handleAcrossMessage(
        address tokenSent,
        uint256 amount,
        bool fillCompleted,
        address relayer,
        bytes memory message
    ) external;

    // New function interface to be used with V3 functions since fillCompleted no longer has any
    // meaning now that partial fills are impossible.
    function handleV3AcrossMessage(
        address tokenSent,
        uint256 amount,
        address relayer,
        bytes memory message
    ) external;
}

/**
 * @title SpokePool
 * @notice Base contract deployed on source and destination chains enabling depositors to transfer assets from source to
 * destination. Deposit orders are fulfilled by off-chain relayers who also interact with this contract. Deposited
 * tokens are locked on the source chain and relayers send the recipient the desired token currency and amount
 * on the destination chain. Locked source chain tokens are later sent over the canonical token bridge to L1 HubPool.
 * Relayers are refunded with destination tokens out of this contract after another off-chain actor, a "data worker",
 * submits a proof that the relayer correctly submitted a relay on this SpokePool.
 * @custom:security-contact bugs@across.to
 */
abstract contract SpokePool is
    V3SpokePoolInterface,
    SpokePoolInterface,
    UUPSUpgradeable,
    ReentrancyGuardUpgradeable,
    MultiCallerUpgradeable,
    EIP712CrossChainUpgradeable
{
//     using SafeERC20Upgradeable for IERC20Upgradeable;
//     using AddressLibUpgradeable for address;

    // Address of the L1 contract that acts as the owner of this SpokePool. This should normally be set to the HubPool
    // address. The crossDomainAdmin address is unused when the SpokePool is deployed to the same chain as the HubPool.
    address public crossDomainAdmin;

    // Address of the L1 contract that will send tokens to and receive tokens from this contract to fund relayer
    // refunds and slow relays.
    address public hubPool;

    // Note: The following two storage variables prefixed with DEPRECATED used to be variables that could be set by
    // the cross-domain admin. Admins ended up not changing these in production, so to reduce
    // gas in deposit/fill functions, we are converting them to private variables to maintain the contract
    // storage layout and replacing them with immutable or constant variables, because retrieving a constant
    // value is cheaper than retrieving a storage variable. Please see out the immutable/constant variable section.
    WETH9Interface private DEPRECATED_wrappedNativeToken;
    uint32 private DEPRECATED_depositQuoteTimeBuffer;

    // Count of deposits is used to construct a unique deposit identifier for this spoke pool.
    uint32 public numberOfDeposits;

    // Whether deposits and fills are disabled.
    bool public pausedFills;
    bool public pausedDeposits;

    // This contract can store as many root bundles as the HubPool chooses to publish here.
    RootBundle[] public rootBundles;

    // Origin token to destination token routings can be turned on or off, which can enable or disable deposits.
    mapping(address => mapping(uint256 => bool)) public enabledDepositRoutes;

    // Each relay is associated with the hash of parameters that uniquely identify the original deposit and a relay
    // attempt for that deposit. The relay itself is just represented as the amount filled so far. The total amount to
    // relay, the fees, and the agents are all parameters included in the hash key.
    mapping(bytes32 => uint256) private DEPRECATED_relayFills;

    // Note: We will likely un-deprecate the fill and deposit counters to implement a better
    // dynamic LP fee mechanism but for now we'll deprecate it to reduce bytecode
    // in deposit/fill functions. These counters are designed to implement a fee mechanism that is based on a
    // canonical history of deposit and fill events and how they update a virtual running balance of liabilities and
    // assets, which then determines the LP fee charged to relays.

    // This keeps track of the worst-case liabilities due to fills.
    // It is never reset. Users should only rely on it to determine the worst-case increase in liabilities between
    // two points. This is used to provide frontrunning protection to ensure the relayer's assumptions about the state
    // upon which their expected repayments are based will not change before their transaction is mined.
    mapping(address => uint256) private DEPRECATED_fillCounter;

    // This keeps track of the total running deposits for each token. This allows depositors to protect themselves from
    // frontrunning that might change their worst-case quote.
    mapping(address => uint256) private DEPRECATED_depositCounter;

    // This tracks the number of identical refunds that have been requested.
    // The intention is to allow an off-chain system to know when this could be a duplicate and ensure that the other
    // requests are known and accounted for.
    mapping(bytes32 => uint256) private DEPRECATED_refundsRequested;

    // Mapping of V3 relay hashes to fill statuses. Distinguished from relayFills
    // to eliminate any chance of collision between pre and post V3 relay hashes.
    mapping(bytes32 => uint256) public fillStatuses;

   /**************************************************************
    *                CONSTANT/IMMUTABLE VARIABLES                *
    **************************************************************/
   // Constant and immutable variables do not take up storage slots and are instead added to the contract bytecode
   // at compile time. The difference between them is that constant variables must be declared inline, meaning
   // that they cannot be changed in production without changing the contract code, while immutable variables
   // can be set in the constructor. Therefore we use the immutable keyword for variables that we might want to be
   // different for each child contract (one obvious example of this is the wrappedNativeToken) or that we might
   // want to update in the future like depositQuoteTimeBuffer. Constants are unlikely to ever be changed.

   // Address of wrappedNativeToken contract for this network. If an origin token matches this, then the caller can
   // optionally instruct this contract to wrap native tokens when depositing (ie ETH->WETH or MATIC->WMATIC).
   /// @custom:oz-upgrades-unsafe-allow state-variable-immutable
   WETH9Interface public immutable wrappedNativeToken;

   // Any deposit quote times greater than or less than this value to the current contract time is blocked. Forces
   // caller to use an approximately "current" realized fee.
   /// @custom:oz-upgrades-unsafe-allow state-variable-immutable
   uint32 public immutable depositQuoteTimeBuffer;

   // The fill deadline can only be set this far into the future from the timestamp of the deposit on this contract.
   /// @custom:oz-upgrades-unsafe-allow state-variable-immutable
   uint32 public immutable fillDeadlineBuffer;

   uint256 public constant MAX_TRANSFER_SIZE = 1e36;

   // Note: this needs to be larger than the max transfer size to ensure that all slow fills are fillable, even if
   // their fees are negative.
   // It's important that it isn't too large, however, as it should be multipliable by ~2e18 without overflowing.
   // 1e40 * 2e18 = 2e58 << 2^255 ~= 5e76
   /// @custom:audit FOLLOWING VARIABLE TO BE DEPRECATED
   uint256 public constant SLOW_FILL_MAX_TOKENS_TO_SEND = 1e40;

   // Set max payout adjustment to something
   /// @custom:audit FOLLOWING VARIABLE TO BE DEPRECATED
   bytes32 public constant UPDATE_DEPOSIT_DETAILS_HASH =
       keccak256(
           "UpdateDepositDetails(uint32 depositId,uint256 originChainId,int64 updatedRelayerFeePct,address updatedRecipient,bytes updatedMessage)"
       );

   bytes32 public constant UPDATE_V3_DEPOSIT_DETAILS_HASH =
       keccak256(
           "UpdateDepositDetails(uint32 depositId,uint256 originChainId,uint256 updatedOutputAmount,address updatedRecipient,bytes updatedMessage)"
       );

   // Default chain Id used to signify that no repayment is requested, for example when executing a slow fill.
   uint256 public constant EMPTY_REPAYMENT_CHAIN_ID = 0;
    // Default address used to signify that no relayer should be credited with a refund, for example
    // when executing a slow fill.
    address public constant EMPTY_RELAYER = address(0);
    // This is the magic value that signals to the off-chain validator
    // that this deposit can never expire. A deposit with this fill deadline should always be eligible for a
    // slow fill, meaning that its output token and input token must be "equivalent". Therefore, this value is only
    // used as a fillDeadline in deposit(), a soon to be deprecated function that also hardcodes outputToken to
    // the zero address, which forces the off-chain validator to replace the output token with the equivalent
    // token for the input token. By using this magic value, off-chain validators do not have to keep
    // this event in their lookback window when querying for expired deposts.
    uint32 public constant INFINITE_FILL_DEADLINE = type(uint32).max;
    /****************************************
     *                EVENTS                *
     ****************************************/
    event SetXDomainAdmin(address indexed newAdmin);
    event SetHubPool(address indexed newHubPool);
    event EnabledDepositRoute(address indexed originToken, uint256 indexed destinationChainId, bool enabled);
    /// @custom:audit FOLLOWING EVENT TO BE DEPRECATED
    event FundsDeposited(
        uint256 amount,
        uint256 originChainId,
        uint256 indexed destinationChainId,
        int64 relayerFeePct,
        uint32 indexed depositId,
        uint32 quoteTimestamp,
        address originToken,
        address recipient,
        address indexed depositor,
        bytes message
    );
    /// @custom:audit FOLLOWING EVENT TO BE DEPRECATED
    event RequestedSpeedUpDeposit(
        int64 newRelayerFeePct,
        uint32 indexed depositId,
        address indexed depositor,
        address updatedRecipient,
        bytes updatedMessage,
        bytes depositorSignature
    );
    /// @custom:audit FOLLOWING EVENT TO BE DEPRECATED
    event FilledRelay(
        uint256 amount,
        uint256 totalFilledAmount,
        uint256 fillAmount,
        uint256 repaymentChainId,
        uint256 indexed originChainId,
        uint256 destinationChainId,
        int64 relayerFeePct,
        int64 realizedLpFeePct,
        uint32 indexed depositId,
        address destinationToken,
        address relayer,
        address indexed depositor,
        address recipient,
        bytes message,
        RelayExecutionInfo updatableRelayData
    );
    event RelayedRootBundle(
        uint32 indexed rootBundleId,
        bytes32 indexed relayerRefundRoot,
        bytes32 indexed slowRelayRoot
    );
    event ExecutedRelayerRefundRoot(
        uint256 amountToReturn,
        uint256 indexed chainId,
        uint256[] refundAmounts,
        uint32 indexed rootBundleId,
        uint32 indexed leafId,
        address l2TokenAddress,
        address[] refundAddresses,
        address caller
    );
    event TokensBridged(
        uint256 amountToReturn,
        uint256 indexed chainId,
        uint32 indexed leafId,
        address indexed l2TokenAddress,
        address caller
    );
    event EmergencyDeleteRootBundle(uint256 indexed rootBundleId);
    event PausedDeposits(bool isPaused);
    event PausedFills(bool isPaused);

    /**
     * @notice Represents data used to fill a deposit.
     * @param relay Relay containing original data linked to deposit. Contains fields that can be
     * overridden by other parameters in the RelayExecution struct.
     * @param relayHash Hash of the relay data.
     * @param updatedRelayerFeePct Actual relayer fee pct to use for this relay.
     * @param updatedRecipient Actual recipient to use for this relay.
     * @param updatedMessage Actual message to use for this relay.
     * @param repaymentChainId Chain ID of the network that the relayer will receive refunds on.
     * @param maxTokensToSend Max number of tokens to pull from relayer.
     * @param maxCount Max count to protect the relayer from frontrunning.
     * @param slowFill Whether this is a slow fill.
     * @param payoutAdjustmentPct Adjustment to the payout amount. Can be used to increase or decrease the payout to
     * allow for rewards or penalties. Used in slow fills.
     */
    /// @custom:audit FOLLOWING STRUCT TO BE DEPRECATED
    struct RelayExecution {
        RelayData relay;
        bytes32 relayHash;
        int64 updatedRelayerFeePct;
        address updatedRecipient;
        bytes updatedMessage;
        uint256 repaymentChainId;
        uint256 maxTokensToSend;
        uint256 maxCount;
        bool slowFill;
        int256 payoutAdjustmentPct;
    }

    /**
     * @notice Packs together information to include in FilledRelay event.
     * @dev This struct is emitted as opposed to its constituent parameters due to the limit on number of
     * parameters in an event.
     * @param recipient Recipient of the relayed funds.
     * @param message Message included in the relay.
     * @param relayerFeePct Relayer fee pct used for this relay.
     * @param isSlowRelay Whether this is a slow relay.
     * @param payoutAdjustmentPct Adjustment to the payout amount.
     */
    /// @custom:audit FOLLOWING STRUCT TO BE DEPRECATED
    struct RelayExecutionInfo {
        address recipient;
        bytes message;
        int64 relayerFeePct;
        bool isSlowRelay;
        int256 payoutAdjustmentPct;
    }

    /**
     * @notice Construct the SpokePool. Normally, logic contracts used in upgradeable proxies shouldn't
     * have constructors since the following code will be executed within the logic contract's state, not the
     * proxy contract's state. However, if we restrict the constructor to setting only immutable variables, then
     * we are safe because immutable variables are included in the logic contract's bytecode rather than its storage.
     * @dev Do not leave an implementation contract uninitialized. An uninitialized implementation contract can be
     * taken over by an attacker, which may impact the proxy. To prevent the implementation contract from being
     * used, you should invoke the _disableInitializers function in the constructor to automatically lock it when
     * it is deployed:
     * @param _wrappedNativeTokenAddress wrappedNativeToken address for this network to set.
     * @param _depositQuoteTimeBuffer depositQuoteTimeBuffer to set. Quote timestamps can't be set more than this amount
     * into the past from the block time of the deposit.
     * @param _fillDeadlineBuffer fillDeadlineBuffer to set. Fill deadlines can't be set more than this amount
     * into the future from the block time of the deposit.
     */
    /// @custom:oz-upgrades-unsafe-allow constructor
    constructor(
        address _wrappedNativeTokenAddress,
        uint32 _depositQuoteTimeBuffer,
        uint32 _fillDeadlineBuffer
    ) {
        wrappedNativeToken = WETH9Interface(_wrappedNativeTokenAddress);
        depositQuoteTimeBuffer = _depositQuoteTimeBuffer;
        fillDeadlineBuffer = _fillDeadlineBuffer;
        _disableInitializers();
    }

    /**
     * @notice Construct the base SpokePool.
     * @param _initialDepositId Starting deposit ID. Set to 0 unless this is a re-deployment in order to mitigate
     * relay hash collisions.
     * @param _crossDomainAdmin Cross domain admin to set. Can be changed by admin.
     * @param _hubPool Hub pool address to set. Can be changed by admin.
     */
  function __SpokePool_init(
      uint32 _initialDepositId,
      address _crossDomainAdmin,
      address _hubPool
  ) public onlyInitializing {
      numberOfDeposits = _initialDepositId;
      __EIP712_init("ACROSS-V2", "1.0.0");
      __UUPSUpgradeable_init();
      __ReentrancyGuard_init();
      _setCrossDomainAdmin(_crossDomainAdmin);
      _setHubPool(_hubPool);
  }

   /****************************************
    *               MODIFIERS              *
    ****************************************/

   /**
    * @dev Function that should revert when `msg.sender` is not authorized to upgrade the contract. Called by
    * {upgradeTo} and {upgradeToAndCall}.
    * @dev This should be set to cross domain admin for specific SpokePool.
    */
   modifier onlyAdmin() {
       _requireAdminSender();
       _;
   }

   modifier unpausedDeposits() {
       require(!pausedDeposits, "Paused deposits");
       _;
   }

   modifier unpausedFills() {
       require(!pausedFills, "Paused fills");
       _;
   }

   /**************************************
    *          ADMIN FUNCTIONS           *
    **************************************/

   // Allows cross domain admin to upgrade UUPS proxy implementation.
   function _authorizeUpgrade(address newImplementation) internal override onlyAdmin {}

   /**
    * @notice Pauses deposit-related functions. This is intended to be used if this contract is deprecated or when
    * something goes awry.
    * @dev Affects `deposit()` but not `speedUpDeposit()`, so that existing deposits can be sped up and still
    * relayed.
    * @param pause true if the call is meant to pause the system, false if the call is meant to unpause it.
    */
   function pauseDeposits(bool pause) public override onlyAdmin nonReentrant {
       pausedDeposits = pause;
       emit PausedDeposits(pause);
   }

   /**
    * @notice Pauses fill-related functions. This is intended to be used if this contract is deprecated or when
    * something goes awry.
    * @dev Affects fillRelayWithUpdatedDeposit() and fillRelay().
    * @param pause true if the call is meant to pause the system, false if the call is meant to unpause it.
    */
   function pauseFills(bool pause) public override onlyAdmin nonReentrant {
       pausedFills = pause;
       emit PausedFills(pause);
   }

   /**
    * @notice Change cross domain admin address. Callable by admin only.
    * @param newCrossDomainAdmin New cross domain admin.
    */
   function setCrossDomainAdmin(address newCrossDomainAdmin) public override onlyAdmin nonReentrant {
       _setCrossDomainAdmin(newCrossDomainAdmin);
   }

   /**
    * @notice Change L1 hub pool address. Callable by admin only.
    * @param newHubPool New hub pool.
    */
   function setHubPool(address newHubPool) public override onlyAdmin nonReentrant {
       _setHubPool(newHubPool);
   }

   /**
    * @notice Enable/Disable an origin token => destination chain ID route for deposits. Callable by admin only.
    * @param originToken Token that depositor can deposit to this contract.
    * @param destinationChainId Chain ID for where depositor wants to receive funds.
    * @param enabled True to enable deposits, False otherwise.
    */
   function setEnableRoute(
       address originToken,
       uint256 destinationChainId,
       bool enabled
   ) public override onlyAdmin nonReentrant {
       enabledDepositRoutes[originToken][destinationChainId] = enabled;
       emit EnabledDepositRoute(originToken, destinationChainId, enabled);
   }

   /**
    * @notice This method stores a new root bundle in this contract that can be executed to refund relayers, fulfill
    * slow relays, and send funds back to the HubPool on L1. This method can only be called by the admin and is
    * designed to be called as part of a cross-chain message from the HubPool's executeRootBundle method.
    * @param relayerRefundRoot Merkle root containing relayer refund leaves that can be individually executed via
    * executeRelayerRefundLeaf().
    * @param slowRelayRoot Merkle root containing slow relay fulfillment leaves that can be individually executed via
    * executeSlowRelayLeaf().
    */
   function relayRootBundle(bytes32 relayerRefundRoot, bytes32 slowRelayRoot) public override onlyAdmin nonReentrant {
       uint32 rootBundleId = uint32(rootBundles.length);
       RootBundle storage rootBundle = rootBundles.push();
       rootBundle.relayerRefundRoot = relayerRefundRoot;
       rootBundle.slowRelayRoot = slowRelayRoot;
       emit RelayedRootBundle(rootBundleId, relayerRefundRoot, slowRelayRoot);
   }

   /**
    * @notice This method is intended to only be used in emergencies where a bad root bundle has reached the
    * SpokePool.
    * @param rootBundleId Index of the root bundle that needs to be deleted. Note: this is intentionally a uint256
    * to ensure that a small input range doesn't limit which indices this method is able to reach.
    */
   function emergencyDeleteRootBundle(uint256 rootBundleId) public override onlyAdmin nonReentrant {
       // Deleting a struct containing a mapping does not delete the mapping in Solidity, therefore the bitmap's
       // data will still remain potentially leading to vulnerabilities down the line. The way around this would
       // be to iterate through every key in the mapping and resetting the value to 0, but this seems expensive and
       // would require a new list in storage to keep track of keys.
       //slither-disable-next-line mapping-deletion
       delete rootBundles[rootBundleId];
       emit EmergencyDeleteRootBundle(rootBundleId);
   }

   /**************************************
    *         DEPOSITOR FUNCTIONS        *
    **************************************/

   /**
    * @notice Called by user to bridge funds from origin to destination chain. Depositor will effectively lock
    * tokens in this contract and receive a destination token on the destination chain. The origin => destination
    * token mapping is stored on the L1 HubPool.
    * @notice The caller must first approve this contract to spend amount of originToken.
    * @notice The originToken => destinationChainId must be enabled.
    * @notice This method is payable because the caller is able to deposit native token if the originToken is
    * wrappedNativeToken and this function will handle wrapping the native token to wrappedNativeToken.
    * @dev Produces a V3FundsDeposited event with an infinite expiry, meaning that this deposit can never expire.
    * Moreover, the event's outputToken is set to 0x0 meaning that this deposit can always be slow filled.
    * @param recipient Address to receive funds at on destination chain.
    * @param originToken Token to lock into this contract to initiate deposit.
    * @param amount Amount of tokens to deposit. Will be amount of tokens to receive less fees.
    * @param destinationChainId Denotes network where user will receive funds from SpokePool by a relayer.
    * @param relayerFeePct % of deposit amount taken out to incentivize a fast relayer.
    * @param quoteTimestamp Timestamp used by relayers to compute this deposit's realizedLPFeePct which is paid
    * to LP pool on HubPool.
    * @param message Arbitrary data that can be used to pass additional information to the recipient along with the tokens.
    * Note: this is intended to be used to pass along instructions for how a contract should use or allocate the tokens.
    */
   function deposit(
       address recipient,
       address originToken,
       uint256 amount,
       uint256 destinationChainId,
       int64 relayerFeePct,
       uint32 quoteTimestamp,
       bytes memory message,
       uint256 // maxCount. Deprecated.
   ) public payable override nonReentrant unpausedDeposits {
       _deposit(
           msg.sender,
           recipient,
           originToken,
           amount,
           destinationChainId,
           relayerFeePct,
           quoteTimestamp,
           message
       );
   }

   /**
    * @notice The only difference between depositFor and deposit is that the depositor address stored
    * in the relay hash can be overridden by the caller. This means that the passed in depositor
    * can speed up the deposit, which is useful if the deposit is taken from the end user to a middle layer
    * contract, like an aggregator or the SpokePoolVerifier, before calling deposit on this contract.
    * @notice The caller must first approve this contract to spend amount of originToken.
    * @notice The originToken => destinationChainId must be enabled.
    * @notice This method is payable because the caller is able to deposit native token if the originToken is
    * wrappedNativeToken and this function will handle wrapping the native token to wrappedNativeToken.
    * @param depositor Address who is credited for depositing funds on origin chain and can speed up the deposit.
    * @param recipient Address to receive funds at on destination chain.
    * @param originToken Token to lock into this contract to initiate deposit.
    * @param amount Amount of tokens to deposit. Will be amount of tokens to receive less fees.
    * @param destinationChainId Denotes network where user will receive funds from SpokePool by a relayer.
    * @param relayerFeePct % of deposit amount taken out to incentivize a fast relayer.
    * @param quoteTimestamp Timestamp used by relayers to compute this deposit's realizedLPFeePct which is paid
    * to LP pool on HubPool.
    * @param message Arbitrary data that can be used to pass additional information to the recipient along with the tokens.
    * Note: this is intended to be used to pass along instructions for how a contract should use or allocate the tokens.
    */
   /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
   function depositFor(
       address depositor,
       address recipient,
       address originToken,
       uint256 amount,
       uint256 destinationChainId,
       int64 relayerFeePct,
       uint32 quoteTimestamp,
       bytes memory message,
       uint256 // maxCount. Deprecated.
   ) public payable nonReentrant unpausedDeposits {
       _deposit(depositor, recipient, originToken, amount, destinationChainId, relayerFeePct, quoteTimestamp, message);
   }

    /**
     * @notice This is a simple wrapper for deposit() that sets the quoteTimestamp to the current SpokePool timestamp.
     * @notice This function is intended for multisig depositors who can accept some LP fee uncertainty in order to lift
     * the quoteTimestamp buffer constraint.
     * @dev Re-orgs may produce invalid fills if the quoteTimestamp moves across a change in HubPool utilisation.
     * @dev The existing function modifiers are already enforced by deposit(), so no additional modifiers are imposed.
     * @param recipient Address to receive funds at on destination chain.
     * @param originToken Token to lock into this contract to initiate deposit.
     * @param amount Amount of tokens to deposit. Will be amount of tokens to receive less fees.
     * @param destinationChainId Denotes network where user will receive funds from SpokePool by a relayer.
     * @param relayerFeePct % of deposit amount taken out to incentivize a fast relayer.
     * @param message Arbitrary data that can be used to pass additional information to the recipient along with the tokens.
     * Note: this is intended to be used to pass along instructions for how a contract should use or allocate the tokens.
     * @param maxCount used to protect the depositor from frontrunning to guarantee their quote remains valid.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function depositNow(
        address recipient,
        address originToken,
        uint256 amount,
        uint256 destinationChainId,
        int64 relayerFeePct,
        bytes memory message,
        uint256 maxCount
    ) public payable {
        deposit(
            recipient,
            originToken,
            amount,
            destinationChainId,
            relayerFeePct,
            uint32(getCurrentTime()),
            message,
            maxCount
        );
    }

    /**
     * @notice This is a simple wrapper for depositFor() that sets the quoteTimestamp to the current SpokePool timestamp.
     * @notice This function is intended for multisig depositors who can accept some LP fee uncertainty in order to lift
     * the quoteTimestamp buffer constraint.
     * @dev Re-orgs may produce invalid fills if the quoteTimestamp moves across a change in HubPool utilisation.
     * @dev The existing function modifiers are already enforced by depositFor(), so no additional modifiers are imposed.
     * @param depositor Address who is credited for depositing funds on origin chain and can speed up the deposit.
     * @param recipient Address to receive funds at on destination chain.
     * @param originToken Token to lock into this contract to initiate deposit.
     * @param amount Amount of tokens to deposit. Will be amount of tokens to receive less fees.
     * @param destinationChainId Denotes network where user will receive funds from SpokePool by a relayer.
     * @param relayerFeePct % of deposit amount taken out to incentivize a fast relayer.
     * @param message Arbitrary data that can be used to pass additional information to the recipient along with the tokens.
     * Note: this is intended to be used to pass along instructions for how a contract should use or allocate the tokens.
     * @param maxCount used to protect the depositor from frontrunning to guarantee their quote remains valid.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function depositForNow(
        address depositor,
        address recipient,
        address originToken,
        uint256 amount,
        uint256 destinationChainId,
        int64 relayerFeePct,
        bytes memory message,
        uint256 maxCount
    ) public payable {
        depositFor(
            depositor,
            recipient,
            originToken,
            amount,
            destinationChainId,
            relayerFeePct,
            uint32(getCurrentTime()),
            message,
            maxCount
        );
    }

    /**
     * @notice Convenience method that depositor can use to signal to relayer to use updated fee.
     * @notice Relayer should only use events emitted by this function to submit fills with updated fees, otherwise they
     * risk their fills getting disputed for being invalid, for example if the depositor never actually signed the
     * update fee message.
     * @notice This function will revert if the depositor did not sign a message containing the updated fee for the
     * deposit ID stored in this contract. If the deposit ID is for another contract, or the depositor address is
     * incorrect, or the updated fee is incorrect, then the signature will not match and this function will revert.
     * @notice This function is not subject to a deposit pause on the off chance that deposits sent before all deposits
     * are paused have very low fees and the user wants to entice a relayer to fill them with a higher fee.
     * @param depositor Signer of the update fee message who originally submitted the deposit. If the deposit doesn't
     * exist, then the relayer will not be able to fill any relay, so the caller should validate that the depositor
     * did in fact submit a relay.
     * @param updatedRelayerFeePct New relayer fee that relayers can use.
     * @param depositId Deposit to update fee for that originated in this contract.
     * @param updatedRecipient New recipient address that should receive the tokens.
     * @param updatedMessage New message that should be provided to the recipient.
     * @param depositorSignature Signed message containing the depositor address, this contract chain ID, the updated
     * relayer fee %, and the deposit ID. This signature is produced by signing a hash of data according to the
     * EIP-712 standard. See more in the _verifyUpdateRelayerFeeMessage() comments.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function speedUpDeposit(
        address depositor,
        int64 updatedRelayerFeePct,
        uint32 depositId,
        address updatedRecipient,
        bytes memory updatedMessage,
        bytes memory depositorSignature
    ) public override nonReentrant {
        require(SignedMath.abs(updatedRelayerFeePct) < 0.5e18, "Invalid relayer fee");

        _verifyUpdateDepositMessage(
            depositor,
            depositId,
            chainId(),
            updatedRelayerFeePct,
            updatedRecipient,
            updatedMessage,
            depositorSignature
        );

        // Assuming the above checks passed, a relayer can take the signature and the updated relayer fee information
        // from the following event to submit a fill with an updated fee %.
        emit RequestedSpeedUpDeposit(
            updatedRelayerFeePct,
            depositId,
            depositor,
            updatedRecipient,
            updatedMessage,
            depositorSignature
        );
    }

    /********************************************
     *         V3 DEPOSITOR FUNCTIONS          *
     ********************************************/

    /**
     * @notice Request to bridge input token cross chain to a destination chain and receive a specified amount
     * of output tokens. The fee paid to relayers and the system should be captured in the spread between output
     * amount and input amount when adjusted to be denominated in the input token. A relayer on the destination
     * chain will send outputAmount of outputTokens to the recipient and receive inputTokens on a repayment
     * chain of their choice. Therefore, the fee should account for destination fee transaction costs,
     * the relayer's opportunity cost of capital while they wait to be refunded following an optimistic challenge
     * window in the HubPool, and the system fee that they'll be charged.
     * @dev On the destination chain, the hash of the deposit data will be used to uniquely identify this deposit, so
     * modifying any params in it will result in a different hash and a different deposit. The hash will comprise
     * all parameters to this function along with this chain's chainId(). Relayers are only refunded for filling
     * deposits with deposit hashes that map exactly to the one emitted by this contract.
     * @param depositor The account credited with the deposit who can request to "speed up" this deposit by modifying
     * the output amount, recipient, and message.
     * @param recipient The account receiving funds on the destination chain. Can be an EOA or a contract. If
     * the output token is the wrapped native token for the chain, then the recipient will receive native token if
     * an EOA or wrapped native token if a contract.
     * @param inputToken The token pulled from the caller's account and locked into this contract to
     * initiate the deposit. The equivalent of this token on the relayer's repayment chain of choice will be sent
     * as a refund. If this is equal to the wrapped native token then the caller can optionally pass in native token as
     * msg.value, as long as msg.value = inputTokenAmount.
     * @param outputToken The token that the relayer will send to the recipient on the destination chain. Must be an
     * ERC20.
     * @param inputAmount The amount of input tokens to pull from the caller's account and lock into this contract.
     * This amount will be sent to the relayer on their repayment chain of choice as a refund following an optimistic
     * challenge window in the HubPool, less a system fee.
     * @param outputAmount The amount of output tokens that the relayer will send to the recipient on the destination.
     * @param destinationChainId The destination chain identifier. Must be enabled along with the input token
     * as a valid deposit route from this spoke pool or this transaction will revert.
     * @param exclusiveRelayer The relayer that will be exclusively allowed to fill this deposit before the
     * exclusivity deadline timestamp. This must be a valid, non-zero address if the exclusivity deadline is
     * greater than the current block.timestamp. If the exclusivity deadline is < currentTime, then this must be
     * address(0), and vice versa if this is address(0).
     * @param quoteTimestamp The HubPool timestamp that is used to determine the system fee paid by the depositor.
     *  This must be set to some time between [currentTime - depositQuoteTimeBuffer, currentTime]
     * where currentTime is block.timestamp on this chain or this transaction will revert.
     * @param fillDeadline The deadline for the relayer to fill the deposit. After this destination chain timestamp,
     * the fill will revert on the destination chain. Must be set between [currentTime, currentTime + fillDeadlineBuffer]
     * where currentTime is block.timestamp on this chain or this transaction will revert.
     * @param exclusivityDeadline The deadline for the exclusive relayer to fill the deposit. After this
     * destination chain timestamp, anyone can fill this deposit on the destination chain. If exclusiveRelayer is set
     * to address(0), then this also must be set to 0, (and vice versa), otherwise this must be set >= current time.
     * @param message The message to send to the recipient on the destination chain if the recipient is a contract.
     * If the message is not empty, the recipient contract must implement handleV3AcrossMessage() or the fill will revert.
     */
    function depositV3(
        address depositor,
        address recipient,
        address inputToken,
        address outputToken,
        uint256 inputAmount,
        uint256 outputAmount,
        uint256 destinationChainId,
        address exclusiveRelayer,
        uint32 quoteTimestamp,
        uint32 fillDeadline,
        uint32 exclusivityDeadline,
        bytes calldata message
    ) public payable override nonReentrant unpausedDeposits {
        // Check that deposit route is enabled for the input token. There are no checks required for the output token
        // which is pulled from the relayer at fill time and passed through this contract atomically to the recipient.
        if (!enabledDepositRoutes[inputToken][destinationChainId]) revert DisabledRoute();

        // Require that quoteTimestamp has a maximum age so that depositors pay an LP fee based on recent HubPool usage.
        // It is assumed that cross-chain timestamps are normally loosely in-sync, but clock drift can occur. If the
        // SpokePool time stalls or lags significantly, it is still possible to make deposits by setting quoteTimestamp
        // within the configured buffer. The owner should pause deposits/fills if this is undesirable.
        // This will underflow if quoteTimestamp is more than depositQuoteTimeBuffer;
        // this is safe but will throw an unintuitive error.

        // slither-disable-next-line timestamp
        uint256 currentTime = getCurrentTime();
        if (currentTime - quoteTimestamp > depositQuoteTimeBuffer) revert InvalidQuoteTimestamp();

        // fillDeadline is relative to the destination chain.
        // Don't allow fillDeadline to be more than several bundles into the future.
        // This limits the maximum required lookback for dataworker and relayer instances.
        // Also, don't allow fillDeadline to be in the past. This poses a potential UX issue if the destination
        // chain time keeping and this chain's time keeping are out of sync but is not really a practical hurdle
        // unless they are significantly out of sync or the depositor is setting very short fill deadlines. This latter
        // situation won't be a problem for honest users.
        if (fillDeadline < currentTime || fillDeadline > currentTime + fillDeadlineBuffer) revert InvalidFillDeadline();

        // As a safety measure, prevent caller from inadvertently locking funds during exclusivity period
        //  by forcing them to specify an exclusive relayer if the exclusivity period
        // is in the future. If this deadline is 0, then the exclusive relayer must also be address(0).
        // @dev Checks if either are > 0 by bitwise or-ing.
        if (uint256(uint160(exclusiveRelayer)) | exclusivityDeadline != 0) {
            // Now that we know one is nonzero, we need to perform checks on each.
            // Check that exclusive relayer is nonzero.
            if (exclusiveRelayer == address(0)) revert InvalidExclusiveRelayer();

            // Check that deadline is in the future.
            if (exclusivityDeadline < currentTime) revert InvalidExclusivityDeadline();
        }

        // No need to sanity check exclusivityDeadline because if its bigger than fillDeadline, then
        // there the full deadline is exclusive, and if its too small, then there is no exclusivity period.

        // If the address of the origin token is a wrappedNativeToken contract and there is a msg.value with the
        // transaction then the user is sending the native token. In this case, the native token should be
        // wrapped.
        if (inputToken == address(wrappedNativeToken) && msg.value > 0) {
            if (msg.value != inputAmount) revert MsgValueDoesNotMatchInputAmount();
            wrappedNativeToken.deposit{ value: msg.value }();
            // Else, it is a normal ERC20. In this case pull the token from the caller as per normal.
            // Note: this includes the case where the L2 caller has WETH (already wrapped ETH) and wants to bridge them.
            // In this case the msg.value will be set to 0, indicating a "normal" ERC20 bridging action.
        } else {
            // msg.value should be 0 if input token isn't the wrapped native token.
            if (msg.value != 0) revert MsgValueDoesNotMatchInputAmount();
            IERC20Upgradeable(inputToken).safeTransferFrom(msg.sender, address(this), inputAmount);
        }

        emit V3FundsDeposited(
            inputToken,
            outputToken,
            inputAmount,
            outputAmount,
            destinationChainId,
            // Increment count of deposits so that deposit ID for this spoke pool is unique.
            numberOfDeposits++,
            quoteTimestamp,
            fillDeadline,
            exclusivityDeadline,
            depositor,
            recipient,
            exclusiveRelayer,
            message
        );
    }

    /**
     * @notice Depositor can use this function to signal to relayer to use updated output amount, recipient,
     * and/or message.
     * @dev the depositor and depositId must match the params in a V3FundsDeposited event that the depositor
     * wants to speed up. The relayer has the option but not the obligation to use this updated information
     * when filling the deposit via fillV3RelayWithUpdatedDeposit().
     * @param depositor Depositor that must sign the depositorSignature and was the original depositor.
     * @param depositId Deposit ID to speed up.
     * @param updatedOutputAmount New output amount to use for this deposit. Should be lower than previous value
     * otherwise relayer has no incentive to use this updated value.
     * @param updatedRecipient New recipient to use for this deposit. Can be modified if the recipient is a contract
     * that expects to receive a message from the relay and for some reason needs to be modified.
     * @param updatedMessage New message to use for this deposit. Can be modified if the recipient is a contract
     * that expects to receive a message from the relay and for some reason needs to be modified.
     * @param depositorSignature Signed EIP712 hashstruct containing the deposit ID. Should be signed by the depositor
     * account. If depositor is a contract, then should implement EIP1271 to sign as a contract. See
     * _verifyUpdateV3DepositMessage() for more details about how this signature should be constructed.
     */
    function speedUpV3Deposit(
        address depositor,
        uint32 depositId,
        uint256 updatedOutputAmount,
        address updatedRecipient,
        bytes calldata updatedMessage,
        bytes calldata depositorSignature
    ) public override nonReentrant {
        _verifyUpdateV3DepositMessage(
            depositor,
            depositId,
            chainId(),
            updatedOutputAmount,
            updatedRecipient,
            updatedMessage,
            depositorSignature
        );

        // Assuming the above checks passed, a relayer can take the signature and the updated deposit information
        // from the following event to submit a fill with updated relay data.
        emit RequestedSpeedUpV3Deposit(
            updatedOutputAmount,
            depositId,
            depositor,
            updatedRecipient,
            updatedMessage,
            depositorSignature
        );
    }

    /**************************************
     *         RELAYER FUNCTIONS          *
     **************************************/

    /**
    /**
     * @notice Called by relayer to fulfill part of a deposit by sending destination tokens to the recipient.
     * Relayer is expected to pass in unique identifying information for deposit that they want to fulfill, and this
     * relay submission will be validated by off-chain data workers who can dispute this relay if any part is invalid.
     * If the relay is valid, then the relayer will be refunded on their desired repayment chain. If relay is invalid,
     * then relayer will not receive any refund.
     * @notice All of the deposit data can be found via on-chain events from the origin SpokePool, except for the
     * realizedLpFeePct which is a function of the HubPool's utilization at the deposit quote time. This fee %
     * is deterministic based on the quote time, so the relayer should just compute it using the canonical algorithm
     * as described in a UMIP linked to the HubPool's identifier.
     * @param depositor Depositor on origin chain who set this chain as the destination chain.
     * @param recipient Specified recipient on this chain.
     * @param destinationToken Token to send to recipient. Should be mapped to the origin token, origin chain ID
     * and this chain ID via a mapping on the HubPool.
     * @param amount Full size of the deposit.
     * @param maxTokensToSend Max amount of tokens to send recipient. If higher than amount, then caller will
     * send recipient the full relay amount.
     * @param repaymentChainId Chain of SpokePool where relayer wants to be refunded after the challenge window has
     * passed.
     * @param originChainId Chain of SpokePool where deposit originated.
     * @param realizedLpFeePct Fee % based on L1 HubPool utilization at deposit quote time. Deterministic based on
     * quote time.
     * @param relayerFeePct Fee % to keep as relayer, specified by depositor.
     * @param depositId Unique deposit ID on origin spoke pool.
     * @param message Message to send to recipient along with tokens.
     * @param maxCount Max count to protect the relayer from frontrunning.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function fillRelay(
        address depositor,
        address recipient,
        address destinationToken,
        uint256 amount,
        uint256 maxTokensToSend,
        uint256 repaymentChainId,
        uint256 originChainId,
        int64 realizedLpFeePct,
        int64 relayerFeePct,
        uint32 depositId,
        bytes memory message,
        uint256 maxCount
    ) public nonReentrant unpausedFills {
        // Each relay attempt is mapped to the hash of data uniquely identifying it, which includes the deposit data
        // such as the origin chain ID and the deposit ID, and the data in a relay attempt such as who the recipient
        // is, which chain and currency the recipient wants to receive funds on, and the relay fees.
        RelayExecution memory relayExecution = RelayExecution({
            relay: SpokePoolInterface.RelayData({
                depositor: depositor,
                recipient: recipient,
                destinationToken: destinationToken,
                amount: amount,
                realizedLpFeePct: realizedLpFeePct,
                relayerFeePct: relayerFeePct,
                depositId: depositId,
                originChainId: originChainId,
                destinationChainId: chainId(),
                message: message
            }),
            relayHash: bytes32(0),
            updatedRelayerFeePct: relayerFeePct,
            updatedRecipient: recipient,
            updatedMessage: message,
            repaymentChainId: repaymentChainId,
            maxTokensToSend: maxTokensToSend,
            slowFill: false,
            payoutAdjustmentPct: 0,
            maxCount: maxCount
        });
        relayExecution.relayHash = _getRelayHash(relayExecution.relay);

        uint256 fillAmountPreFees = _fillRelay(relayExecution);
        _emitFillRelay(relayExecution, fillAmountPreFees);
    }

    /**
     * @notice Called by relayer to execute same logic as calling fillRelay except that relayer is using an updated
     * relayer fee %. The fee % must have been emitted in a message cryptographically signed by the depositor.
     * @notice By design, the depositor probably emitted the message with the updated fee by calling speedUpDeposit().
     * @param depositor Depositor on origin chain who set this chain as the destination chain.
     * @param recipient Specified recipient on this chain.
     * @param destinationToken Token to send to recipient. Should be mapped to the origin token, origin chain ID
     * and this chain ID via a mapping on the HubPool.
     * @param amount Full size of the deposit.
     * @param maxTokensToSend Max amount of tokens to send recipient. If higher than amount, then caller will
     * send recipient the full relay amount.
     * @param repaymentChainId Chain of SpokePool where relayer wants to be refunded after the challenge window has
     * passed.
     * @param originChainId Chain of SpokePool where deposit originated.
     * @param realizedLpFeePct Fee % based on L1 HubPool utilization at deposit quote time. Deterministic based on
     * quote time.
     * @param relayerFeePct Original fee % to keep as relayer set by depositor.
     * @param updatedRelayerFeePct New fee % to keep as relayer also specified by depositor.
     * @param depositId Unique deposit ID on origin spoke pool.
     * @param message Original message that was sent along with this deposit.
     * @param updatedMessage Modified message that the depositor signed when updating parameters.
     * @param depositorSignature Signed message containing the depositor address, this contract chain ID, the updated
     * relayer fee %, and the deposit ID. This signature is produced by signing a hash of data according to the
     * EIP-712 standard. See more in the _verifyUpdateRelayerFeeMessage() comments.
     * @param maxCount Max fill count to protect the relayer from frontrunning.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function fillRelayWithUpdatedDeposit(
        address depositor,
        address recipient,
        address updatedRecipient,
        address destinationToken,
        uint256 amount,
        uint256 maxTokensToSend,
        uint256 repaymentChainId,
        uint256 originChainId,
        int64 realizedLpFeePct,
        int64 relayerFeePct,
        int64 updatedRelayerFeePct,
        uint32 depositId,
        bytes memory message,
        bytes memory updatedMessage,
        bytes memory depositorSignature,
        uint256 maxCount
    ) public override nonReentrant unpausedFills {
        RelayExecution memory relayExecution = RelayExecution({
            relay: SpokePoolInterface.RelayData({
                depositor: depositor,
                recipient: recipient,
                destinationToken: destinationToken,
                amount: amount,
                realizedLpFeePct: realizedLpFeePct,
                relayerFeePct: relayerFeePct,
                depositId: depositId,
                originChainId: originChainId,
                destinationChainId: chainId(),
                message: message
            }),
            relayHash: bytes32(0),
            updatedRelayerFeePct: updatedRelayerFeePct,
            updatedRecipient: updatedRecipient,
            updatedMessage: updatedMessage,
            repaymentChainId: repaymentChainId,
            maxTokensToSend: maxTokensToSend,
            slowFill: false,
            payoutAdjustmentPct: 0,
            maxCount: maxCount
        });
        relayExecution.relayHash = _getRelayHash(relayExecution.relay);

        _verifyUpdateDepositMessage(
            depositor,
            depositId,
            originChainId,
            updatedRelayerFeePct,
            updatedRecipient,
            updatedMessage,
            depositorSignature
        );
        uint256 fillAmountPreFees = _fillRelay(relayExecution);
        _emitFillRelay(relayExecution, fillAmountPreFees);
    }

    /******************************************
     *         V3 RELAYER FUNCTIONS          *
     ******************************************/

    /**
     * @notice Fulfill request to bridge cross chain by sending specified output tokens to the recipient.
     * @dev The fee paid to relayers and the system should be captured in the spread between output
     * amount and input amount when adjusted to be denominated in the input token. A relayer on the destination
     * chain will send outputAmount of outputTokens to the recipient and receive inputTokens on a repayment
     * chain of their choice. Therefore, the fee should account for destination fee transaction costs, the
     * relayer's opportunity cost of capital while they wait to be refunded following an optimistic challenge
     * window in the HubPool, and a system fee charged to relayers.
     * @dev The hash of the relayData will be used to uniquely identify the deposit to fill, so
     * modifying any params in it will result in a different hash and a different deposit. The hash will comprise
     * all parameters passed to depositV3() on the origin chain along with that chain's chainId(). This chain's
     * chainId() must therefore match the destinationChainId passed into depositV3.
     * Relayers are only refunded for filling deposits with deposit hashes that map exactly to the one emitted by the
     * origin SpokePool therefore the relayer should not modify any params in relayData.
     * @dev Cannot fill more than once. Partial fills are not supported.
     * @param relayData struct containing all the data needed to identify the deposit to be filled. Should match
     * all the same-named parameters emitted in the origin chain V3FundsDeposited event.
     * - depositor: The account credited with the deposit who can request to "speed up" this deposit by modifying
     * the output amount, recipient, and message.
     * - recipient The account receiving funds on this chain. Can be an EOA or a contract. If
     * the output token is the wrapped native token for the chain, then the recipient will receive native token if
     * an EOA or wrapped native token if a contract.
     * - inputToken: The token pulled from the caller's account to initiate the deposit. The equivalent of this
     * token on the repayment chain will be sent as a refund to the caller.
     * - outputToken The token that the caller will send to the recipient on the destination chain. Must be an
     * ERC20.
     * - inputAmount: This amount, less a system fee, will be sent to the caller on their repayment chain of choice as a refund
     * following an optimistic challenge window in the HubPool.
     * - outputAmount: The amount of output tokens that the caller will send to the recipient.
     * - originChainId: The origin chain identifier.
     * - exclusiveRelayer The relayer that will be exclusively allowed to fill this deposit before the
     * exclusivity deadline timestamp.
     * - fillDeadline The deadline for the caller to fill the deposit. After this timestamp,
     * the fill will revert on the destination chain.
     * - exclusivityDeadline: The deadline for the exclusive relayer to fill the deposit. After this
     * timestamp, anyone can fill this deposit.
     * - message The message to send to the recipient if the recipient is a contract that implements a
     * handleV3AcrossMessage() public function
     * @param repaymentChainId Chain of SpokePool where relayer wants to be refunded after the challenge window has
     * passed. Will receive inputAmount of the equivalent token to inputToken on the repayment chain.
     */
    function fillV3Relay(V3RelayData calldata relayData, uint256 repaymentChainId)
        public
        override
        nonReentrant
        unpausedFills
    {
        // Exclusivity deadline is inclusive and is the latest timestamp that the exclusive relayer has sole right
        // to fill the relay.
        if (relayData.exclusivityDeadline >= getCurrentTime() && relayData.exclusiveRelayer != msg.sender) {
            revert NotExclusiveRelayer();
        }

        V3RelayExecutionParams memory relayExecution = V3RelayExecutionParams({
            relay: relayData,
            relayHash: _getV3RelayHash(relayData),
            updatedOutputAmount: relayData.outputAmount,
            updatedRecipient: relayData.recipient,
            updatedMessage: relayData.message,
            repaymentChainId: repaymentChainId
        });

        _fillRelayV3(relayExecution, msg.sender, false);
    }

    /**
     * @notice Identical to fillV3Relay except that the relayer wants to use a depositor's updated output amount,
     * recipient, and/or message. The relayer should only use this function if they can supply a message signed
     * by the depositor that contains the fill's matching deposit ID along with updated relay parameters.
     * If the signature can be verified, then this function will emit a FilledV3Event that will be used by
     * the system for refund verification purposes. In otherwords, this function is an alternative way to fill a
     * a deposit than fillV3Relay.
     * @dev Subject to same exclusivity deadline rules as fillV3Relay().
     * @param relayData struct containing all the data needed to identify the deposit to be filled. See fillV3Relay().
     * @param repaymentChainId Chain of SpokePool where relayer wants to be refunded after the challenge window has
     * passed. See fillV3Relay().
     * @param updatedOutputAmount New output amount to use for this deposit.
     * @param updatedRecipient New recipient to use for this deposit.
     * @param updatedMessage New message to use for this deposit.
     * @param depositorSignature Signed EIP712 hashstruct containing the deposit ID. Should be signed by the depositor
     * account.
     */
    function fillV3RelayWithUpdatedDeposit(
        V3RelayData calldata relayData,
        uint256 repaymentChainId,
        uint256 updatedOutputAmount,
        address updatedRecipient,
        bytes calldata updatedMessage,
        bytes calldata depositorSignature
    ) public override nonReentrant unpausedFills {
        // Exclusivity deadline is inclusive and is the latest timestamp that the exclusive relayer has sole right
        // to fill the relay.
        if (relayData.exclusivityDeadline >= getCurrentTime() && relayData.exclusiveRelayer != msg.sender) {
            revert NotExclusiveRelayer();
        }

        V3RelayExecutionParams memory relayExecution = V3RelayExecutionParams({
            relay: relayData,
            relayHash: _getV3RelayHash(relayData),
            updatedOutputAmount: updatedOutputAmount,
            updatedRecipient: updatedRecipient,
            updatedMessage: updatedMessage,
            repaymentChainId: repaymentChainId
        });

        _verifyUpdateV3DepositMessage(
            relayData.depositor,
            relayData.depositId,
            relayData.originChainId,
            updatedOutputAmount,
            updatedRecipient,
            updatedMessage,
            depositorSignature
        );

        _fillRelayV3(relayExecution, msg.sender, false);
    }

    /**
     * @notice Request Across to send LP funds to this contract to fulfill a slow fill relay
     * for a deposit in the next bundle.
     * @dev Slow fills are not possible unless the input and output tokens are "equivalent", i.e.
     * they route to the same L1 token via PoolRebalanceRoutes.
     * @dev Slow fills are created by inserting slow fill objects into a merkle tree that is included
     * in the next HubPool "root bundle". Once the optimistic challenge window has passed, the HubPool
     * will relay the slow root to this chain via relayRootBundle(). Once the slow root is relayed,
     * the slow fill can be executed by anyone who calls executeV3SlowRelayLeaf().
     * @dev Cannot request a slow fill if the fill deadline has passed.
     * @dev Cannot request a slow fill if the relay has already been filled or a slow fill has already been requested.
     * @param relayData struct containing all the data needed to identify the deposit that should be
     * slow filled. If any of the params are missing or different from the origin chain deposit,
     * then Across will not include a slow fill for the intended deposit.
     */
    function requestV3SlowFill(V3RelayData calldata relayData) public override nonReentrant unpausedFills {
        // If a depositor has set an exclusivity deadline, then only the exclusive relayer should be able to
        // fast fill within this deadline. Moreover, the depositor should expect to get *fast* filled within
        // this deadline, not slow filled. As a simplifying assumption, we will not allow slow fills to be requested
        // this exclusivity period.
        if (relayData.exclusivityDeadline >= getCurrentTime()) {
            revert NoSlowFillsInExclusivityWindow();
        }
        if (relayData.fillDeadline < getCurrentTime()) revert ExpiredFillDeadline();

        bytes32 relayHash = _getV3RelayHash(relayData);
        if (fillStatuses[relayHash] != uint256(FillStatus.Unfilled)) revert InvalidSlowFillRequest();
        fillStatuses[relayHash] = uint256(FillStatus.RequestedSlowFill);

        emit RequestedV3SlowFill(
            relayData.inputToken,
            relayData.outputToken,
            relayData.inputAmount,
            relayData.outputAmount,
            relayData.originChainId,
            relayData.depositId,
            relayData.fillDeadline,
            relayData.exclusivityDeadline,
            relayData.exclusiveRelayer,
            relayData.depositor,
            relayData.recipient,
            relayData.message
        );
    }

    /**************************************
     *         DATA WORKER FUNCTIONS      *
     **************************************/

    /**
     * @notice Executes a slow relay leaf stored as part of a root bundle. Will send the full amount remaining in the
     * relay to the recipient, less fees.
     * @dev This function assumes that the relay's destination chain ID is the current chain ID, which prevents
     * the caller from executing a slow relay intended for another chain on this chain.
     * @param depositor Depositor on origin chain who set this chain as the destination chain.
     * @param recipient Specified recipient on this chain.
     * @param destinationToken Token to send to recipient. Should be mapped to the origin token, origin chain ID
     * and this chain ID via a mapping on the HubPool.
     * @param amount Full size of the deposit.
     * @param originChainId Chain of SpokePool where deposit originated.
     * @param realizedLpFeePct Fee % based on L1 HubPool utilization at deposit quote time. Deterministic based on
     * quote time.
     * @param relayerFeePct Original fee % to keep as relayer set by depositor.
     * @param depositId Unique deposit ID on origin spoke pool.
     * @param rootBundleId Unique ID of root bundle containing slow relay root that this leaf is contained in.
     * @param message Message to send to the recipient if the recipient is a contract.
     * @param payoutAdjustment Adjustment to the payout amount. Can be used to increase or decrease the payout to allow
     * for rewards or penalties.
     * @param proof Inclusion proof for this leaf in slow relay root in root bundle.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function executeSlowRelayLeaf(
        address depositor,
        address recipient,
        address destinationToken,
        uint256 amount,
        uint256 originChainId,
        int64 realizedLpFeePct,
        int64 relayerFeePct,
        uint32 depositId,
        uint32 rootBundleId,
        bytes memory message,
        int256 payoutAdjustment,
        bytes32[] memory proof
    ) public override nonReentrant {
        _preExecuteLeafHook(destinationToken);
        _executeSlowRelayLeaf(
            depositor,
            recipient,
            destinationToken,
            amount,
            originChainId,
            chainId(),
            realizedLpFeePct,
            relayerFeePct,
            depositId,
            rootBundleId,
            message,
            payoutAdjustment,
            proof
        );
    }
 
    /**
     * @notice Executes a slow relay leaf stored as part of a root bundle relayed by the HubPool.
     * @dev Executing a slow fill leaf is equivalent to filling the relayData so this function cannot be used to
     * double fill a recipient. The relayData that is filled is included in the slowFillLeaf and is hashed
     * like any other fill sent through fillV3Relay().
     * @dev There is no relayer credited with filling this relay since funds are sent directly out of this contract.
     * @param slowFillLeaf Contains all data necessary to uniquely identify a relay for this chain. This struct is
     * hashed and included in a merkle root that is relayed to all spoke pools.
     * - relayData: struct containing all the data needed to identify the original deposit to be slow filled.
     * - chainId: chain identifier where slow fill leaf should be executed. If this doesn't match this chain's
     * chainId, then this function will revert.
     * - updatedOutputAmount: Amount to be sent to recipient out of this contract's balance. Can be set differently
     * from relayData.outputAmount to charge a different fee because this deposit was "slow" filled. Usually,
     * this will be set higher to reimburse the recipient for waiting for the slow fill.
     * @param rootBundleId Unique ID of root bundle containing slow relay root that this leaf is contained in.
     * @param proof Inclusion proof for this leaf in slow relay root in root bundle.
     */
    function executeV3SlowRelayLeaf(
        V3SlowFill calldata slowFillLeaf,
        uint32 rootBundleId,
        bytes32[] calldata proof
    ) public override nonReentrant {
        V3RelayData memory relayData = slowFillLeaf.relayData;

        _preExecuteLeafHook(relayData.outputToken);

        // @TODO In the future consider allowing way for slow fill leaf to be created with updated
        // deposit params like outputAmount, message and recipient.
        V3RelayExecutionParams memory relayExecution = V3RelayExecutionParams({
            relay: relayData,
            relayHash: _getV3RelayHash(relayData),
            updatedOutputAmount: slowFillLeaf.updatedOutputAmount,
            updatedRecipient: relayData.recipient,
            updatedMessage: relayData.message,
            repaymentChainId: EMPTY_REPAYMENT_CHAIN_ID // Repayment not relevant for slow fills.
        });

        _verifyV3SlowFill(relayExecution, rootBundleId, proof);

        // - No relayer to refund for slow fill executions.
        _fillRelayV3(relayExecution, EMPTY_RELAYER, true);
    }

    /**
     * @notice Executes a relayer refund leaf stored as part of a root bundle. Will send the relayer the amount they
     * sent to the recipient plus a relayer fee.
     * @param rootBundleId Unique ID of root bundle containing relayer refund root that this leaf is contained in.
     * @param relayerRefundLeaf Contains all data necessary to reconstruct leaf contained in root bundle and to
     * refund relayer. This data structure is explained in detail in the SpokePoolInterface.
     * @param proof Inclusion proof for this leaf in relayer refund root in root bundle.
     */
    function executeRelayerRefundLeaf(
        uint32 rootBundleId,
        SpokePoolInterface.RelayerRefundLeaf memory relayerRefundLeaf,
        bytes32[] memory proof
    ) public payable virtual override nonReentrant {
        _preExecuteLeafHook(relayerRefundLeaf.l2TokenAddress);

        if (relayerRefundLeaf.chainId != chainId()) revert InvalidChainId();

        RootBundle storage rootBundle = rootBundles[rootBundleId];

        // Check that proof proves that relayerRefundLeaf is contained within the relayer refund root.
        // Note: This should revert if the relayerRefundRoot is uninitialized.
        if (!MerkleLib.verifyRelayerRefund(rootBundle.relayerRefundRoot, relayerRefundLeaf, proof))
            revert InvalidMerkleProof();

        _setClaimedLeaf(rootBundleId, relayerRefundLeaf.leafId);

        _distributeRelayerRefunds(
            relayerRefundLeaf.chainId,
            relayerRefundLeaf.amountToReturn,
            relayerRefundLeaf.refundAmounts,
            relayerRefundLeaf.leafId,
            relayerRefundLeaf.l2TokenAddress,
            relayerRefundLeaf.refundAddresses
        );

        emit ExecutedRelayerRefundRoot(
            relayerRefundLeaf.amountToReturn,
            relayerRefundLeaf.chainId,
            relayerRefundLeaf.refundAmounts,
            rootBundleId,
            relayerRefundLeaf.leafId,
            relayerRefundLeaf.l2TokenAddress,
            relayerRefundLeaf.refundAddresses,
            msg.sender
        );
    }

    /**************************************
     *           VIEW FUNCTIONS           *
     **************************************/

    /**
     * @notice Returns chain ID for this network.
     * @dev Some L2s like ZKSync don't support the CHAIN_ID opcode so we allow the implementer to override this.
     */
    function chainId() public view virtual override returns (uint256) {
        return block.chainid;
    }

    /**
     * @notice Gets the current time.
     * @return uint for the current timestamp.
     */
    function getCurrentTime() public view virtual returns (uint256) {
        return block.timestamp; // solhint-disable-line not-rely-on-time
    }

    /**************************************
     *         INTERNAL FUNCTIONS         *
     **************************************/

    function _deposit(
        address depositor,
        address recipient,
        address originToken,
        uint256 amount,
        uint256 destinationChainId,
        int64 relayerFeePct,
        uint32 quoteTimestamp,
        bytes memory message
    ) internal {
        // Check that deposit route is enabled.
        require(enabledDepositRoutes[originToken][destinationChainId], "Disabled route");

        // We limit the relay fees to prevent the user spending all their funds on fees.
        require(SignedMath.abs(relayerFeePct) < 0.5e18, "Invalid relayer fee");
        require(amount <= MAX_TRANSFER_SIZE, "Amount too large");

        // Require that quoteTimestamp has a maximum age so that depositors pay an LP fee based on recent HubPool usage.
        // It is assumed that cross-chain timestamps are normally loosely in-sync, but clock drift can occur. If the
        // SpokePool time stalls or lags significantly, it is still possible to make deposits by setting quoteTimestamp
        // within the configured buffer. The owner should pause deposits if this is undesirable. This will underflow if
        // quoteTimestamp is more than depositQuoteTimeBuffer; this is safe but will throw an unintuitive error.

        // slither-disable-next-line timestamp
        require(getCurrentTime() - quoteTimestamp <= depositQuoteTimeBuffer, "invalid quoteTimestamp");

        // Increment count of deposits so that deposit ID for this spoke pool is unique.
        uint32 newDepositId = numberOfDeposits++;

        // If the address of the origin token is a wrappedNativeToken contract and there is a msg.value with the
        // transaction then the user is sending ETH. In this case, the ETH should be deposited to wrappedNativeToken.
        if (originToken == address(wrappedNativeToken) && msg.value > 0) {
            require(msg.value == amount, "msg.value must match amount");
            wrappedNativeToken.deposit{ value: msg.value }();
            // Else, it is a normal ERC20. In this case pull the token from the user's wallet as per normal.
            // Note: this includes the case where the L2 user has WETH (already wrapped ETH) and wants to bridge them.
            // In this case the msg.value will be set to 0, indicating a "normal" ERC20 bridging action.
        } else IERC20Upgradeable(originToken).safeTransferFrom(msg.sender, address(this), amount);

        emit V3FundsDeposited(
            originToken, // inputToken
            address(0), // outputToken. Setting this to 0x0 means that the outputToken should be assumed to be the
            // canonical token for the destination chain matching the inputToken. Therefore, this deposit
            // can always be slow filled.
            // - setting token to 0x0 will signal to off-chain validator that the "equivalent"
            // token as the inputToken for the destination chain should be replaced here.
            amount, // inputAmount
            _computeAmountPostFees(amount, relayerFeePct), // outputAmount
            // - output amount will be the deposit amount less relayerFeePct, which should now be set
            // equal to realizedLpFeePct + gasFeePct + capitalCostFeePct where (gasFeePct + capitalCostFeePct)
            // is equal to the old usage of `relayerFeePct`.
            destinationChainId,
            newDepositId,
            quoteTimestamp,
            INFINITE_FILL_DEADLINE, // fillDeadline. Default to infinite expiry because
            // expired deposits refunds could be a breaking change for existing users of this function.
            0, // exclusivityDeadline. Setting this to 0 along with the exclusiveRelayer to 0x0 means that there
            // is no exclusive deadline
            depositor,
            recipient,
            address(0), // exclusiveRelayer. Setting this to 0x0 will signal to off-chain validator that there
            // is no exclusive relayer.
            message
        );
    }

    function _distributeRelayerRefunds(
        uint256 _chainId,
        uint256 amountToReturn,
        uint256[] memory refundAmounts,
        uint32 leafId,
        address l2TokenAddress,
        address[] memory refundAddresses
    ) internal {
        if (refundAddresses.length != refundAmounts.length) revert InvalidMerkleLeaf();

        // Send each relayer refund address the associated refundAmount for the L2 token address.
        // Note: Even if the L2 token is not enabled on this spoke pool, we should still refund relayers.
        uint256 length = refundAmounts.length;
        for (uint256 i = 0; i < length; ++i) {
            uint256 amount = refundAmounts[i];
            if (amount > 0) IERC20Upgradeable(l2TokenAddress).safeTransfer(refundAddresses[i], amount);
        }

        // If leaf's amountToReturn is positive, then send L2 --> L1 message to bridge tokens back via
        // chain-specific bridging method.
        if (amountToReturn > 0) {
            _bridgeTokensToHubPool(amountToReturn, l2TokenAddress);

            emit TokensBridged(amountToReturn, _chainId, leafId, l2TokenAddress, msg.sender);
        }
    }

    // Verifies inclusion proof of leaf in root and sends recipient remainder of relay. Marks relay as filled.
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _executeSlowRelayLeaf(
        address depositor,
        address recipient,
        address destinationToken,
        uint256 amount,
        uint256 originChainId,
        uint256 destinationChainId,
        int64 realizedLpFeePct,
        int64 relayerFeePct,
        uint32 depositId,
        uint32 rootBundleId,
        bytes memory message,
        int256 payoutAdjustmentPct,
        bytes32[] memory proof
    ) internal {
        RelayExecution memory relayExecution = RelayExecution({
            relay: SpokePoolInterface.RelayData({
                depositor: depositor,
                recipient: recipient,
                destinationToken: destinationToken,
                amount: amount,
                realizedLpFeePct: realizedLpFeePct,
                relayerFeePct: relayerFeePct,
                depositId: depositId,
                originChainId: originChainId,
                destinationChainId: destinationChainId,
                message: message
            }),
            relayHash: bytes32(0),
            updatedRelayerFeePct: 0,
            updatedRecipient: recipient,
            updatedMessage: message,
            repaymentChainId: 0,
            maxTokensToSend: SLOW_FILL_MAX_TOKENS_TO_SEND,
            slowFill: true,
            payoutAdjustmentPct: payoutAdjustmentPct,
            maxCount: type(uint256).max
        });
        relayExecution.relayHash = _getRelayHash(relayExecution.relay);

        _verifySlowFill(relayExecution, rootBundleId, proof);

        // Note: use relayAmount as the max amount to send, so the relay is always completely filled by the contract's
        // funds in all cases. As this is a slow relay we set the relayerFeePct to 0. This effectively refunds the
        // relayer component of the relayerFee thereby only charging the depositor the LpFee.
        uint256 fillAmountPreFees = _fillRelay(relayExecution);

        // Note: Set repayment chain ID to 0 to indicate that there is no repayment to be made. The off-chain data
        // worker can use repaymentChainId=0 as a signal to ignore such relays for refunds. Also, set the relayerFeePct
        // to 0 as slow relays do not pay the caller of this method (depositor is refunded this fee).
        _emitFillRelay(relayExecution, fillAmountPreFees);
    }

    function _setCrossDomainAdmin(address newCrossDomainAdmin) internal {
        require(newCrossDomainAdmin != address(0), "Bad bridge router address");
        crossDomainAdmin = newCrossDomainAdmin;
        emit SetXDomainAdmin(newCrossDomainAdmin);
    }

    function _setHubPool(address newHubPool) internal {
        require(newHubPool != address(0), "Bad hub pool address");
        hubPool = newHubPool;
        emit SetHubPool(newHubPool);
    }

    function _preExecuteLeafHook(address) internal virtual {
        // This method by default is a no-op. Different child spoke pools might want to execute functionality here
        // such as wrapping any native tokens owned by the contract into wrapped tokens before proceeding with
        // executing the leaf.
    }

    // Should be overriden by implementing contract depending on how L2 handles sending tokens to L1.
    function _bridgeTokensToHubPool(uint256 amountToReturn, address l2TokenAddress) internal virtual;

    function _setClaimedLeaf(uint32 rootBundleId, uint32 leafId) internal {
        RootBundle storage rootBundle = rootBundles[rootBundleId];

        // Verify the leafId in the leaf has not yet been claimed.
        if (MerkleLib.isClaimed(rootBundle.claimedBitmap, leafId)) revert ClaimedMerkleLeaf();

        // Set leaf as claimed in bitmap. This is passed by reference to the storage rootBundle.
        MerkleLib.setClaimed(rootBundle.claimedBitmap, leafId);
    }

    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _verifyUpdateDepositMessage(
        address depositor,
        uint32 depositId,
        uint256 originChainId,
        int64 updatedRelayerFeePct,
        address updatedRecipient,
        bytes memory updatedMessage,
        bytes memory depositorSignature
    ) internal view {
        // A depositor can request to modify an un-relayed deposit by signing a hash containing the updated
        // details and information uniquely identifying the deposit to relay. This information ensures
        // that this signature cannot be re-used for other deposits.
        // Note: We use the EIP-712 (https://eips.ethereum.org/EIPS/eip-712) standard for hashing and signing typed data.
        // Specifically, we use the version of the encoding known as "v4", as implemented by the JSON RPC method
        // `eth_signedTypedDataV4` in MetaMask (https://docs.metamask.io/guide/signing-data.html).
        bytes32 expectedTypedDataV4Hash = _hashTypedDataV4(
            // EIP-712 compliant hash struct: https://eips.ethereum.org/EIPS/eip-712#definition-of-hashstruct
            keccak256(
                abi.encode(
                    UPDATE_DEPOSIT_DETAILS_HASH,
                    depositId,
                    originChainId,
                    updatedRelayerFeePct,
                    updatedRecipient,
                    keccak256(updatedMessage)
                )
            ),
            // By passing in the origin chain id, we enable the verification of the signature on a different chain
            originChainId
        );
        _verifyDepositorSignature(depositor, expectedTypedDataV4Hash, depositorSignature);
    }

    function _verifyUpdateV3DepositMessage(
        address depositor,
        uint32 depositId,
        uint256 originChainId,
        uint256 updatedOutputAmount,
        address updatedRecipient,
        bytes memory updatedMessage,
        bytes memory depositorSignature
    ) internal view {
        // A depositor can request to modify an un-relayed deposit by signing a hash containing the updated
        // details and information uniquely identifying the deposit to relay. This information ensures
        // that this signature cannot be re-used for other deposits.
        // Note: We use the EIP-712 (https://eips.ethereum.org/EIPS/eip-712) standard for hashing and signing typed data.
        // Specifically, we use the version of the encoding known as "v4", as implemented by the JSON RPC method
        // `eth_signedTypedDataV4` in MetaMask (https://docs.metamask.io/guide/signing-data.html).
        bytes32 expectedTypedDataV4Hash = _hashTypedDataV4(
            // EIP-712 compliant hash struct: https://eips.ethereum.org/EIPS/eip-712#definition-of-hashstruct
            keccak256(
                abi.encode(
                    UPDATE_V3_DEPOSIT_DETAILS_HASH,
                    depositId,
                    originChainId,
                    updatedOutputAmount,
                    updatedRecipient,
                    keccak256(updatedMessage)
                )
            ),
            // By passing in the origin chain id, we enable the verification of the signature on a different chain
            originChainId
        );
        _verifyDepositorSignature(depositor, expectedTypedDataV4Hash, depositorSignature);
    }

    // This function is isolated and made virtual to allow different L2's to implement chain specific recovery of
    // signers from signatures because some L2s might not support ecrecover. To be safe, consider always reverting
    // this function for L2s where ecrecover is different from how it works on Ethereum, otherwise there is the
    // potential to forge a signature from the depositor using a different private key than the original depositor's.
    function _verifyDepositorSignature(
        address depositor,
        bytes32 ethSignedMessageHash,
        bytes memory depositorSignature
    ) internal view virtual {
        // Note:
        // - We don't need to worry about reentrancy from a contract deployed at the depositor address since the method
        //   `SignatureChecker.isValidSignatureNow` is a view method. Re-entrancy can happen, but it cannot affect state.
        // - EIP-1271 signatures are supported. This means that a signature valid now, may not be valid later and vice-versa.
        // - For an EIP-1271 signature to work, the depositor contract address must map to a deployed contract on the destination
        //   chain that can validate the signature.
        // - Regular signatures from an EOA are also supported.
        bool isValid = SignatureChecker.isValidSignatureNow(depositor, ethSignedMessageHash, depositorSignature);
        require(isValid, "invalid signature");
    }

    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _verifySlowFill(
        RelayExecution memory relayExecution,
        uint32 rootBundleId,
        bytes32[] memory proof
    ) internal view {
        SlowFill memory slowFill = SlowFill({
            relayData: relayExecution.relay,
            payoutAdjustmentPct: relayExecution.payoutAdjustmentPct
        });

        require(
            MerkleLib.verifySlowRelayFulfillment(rootBundles[rootBundleId].slowRelayRoot, slowFill, proof),
            "Invalid slow relay proof"
        );
    }

    function _verifyV3SlowFill(
        V3RelayExecutionParams memory relayExecution,
        uint32 rootBundleId,
        bytes32[] memory proof
    ) internal view {
        V3SlowFill memory slowFill = V3SlowFill({
            relayData: relayExecution.relay,
            chainId: chainId(),
            updatedOutputAmount: relayExecution.updatedOutputAmount
        });

        if (!MerkleLib.verifyV3SlowRelayFulfillment(rootBundles[rootBundleId].slowRelayRoot, slowFill, proof))
            revert InvalidMerkleProof();
    }

    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _computeAmountPreFees(uint256 amount, int64 feesPct) private pure returns (uint256) {
        return (1e18 * amount) / uint256((int256(1e18) - feesPct));
    }

    function _computeAmountPostFees(uint256 amount, int256 feesPct) private pure returns (uint256) {
        return (amount * uint256(int256(1e18) - feesPct)) / 1e18;
    }

    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _getRelayHash(SpokePoolInterface.RelayData memory relayData) private pure returns (bytes32) {
        return keccak256(abi.encode(relayData));
    }

    function _getV3RelayHash(V3RelayData memory relayData) private view returns (bytes32) {
        return keccak256(abi.encode(relayData, chainId()));
    }

    // Unwraps ETH and does a transfer to a recipient address. If the recipient is a smart contract then sends wrappedNativeToken.
    function _unwrapwrappedNativeTokenTo(address payable to, uint256 amount) internal {
        if (address(to).isContract()) {
            IERC20Upgradeable(address(wrappedNativeToken)).safeTransfer(to, amount);
        } else {
            wrappedNativeToken.withdraw(amount);
            AddressLibUpgradeable.sendValue(to, amount);
        }
    }

    /**
     * @notice Caller specifies the max amount of tokens to send to user. Based on this amount and the amount of the
     * relay remaining (as stored in the relayFills mapping), pull the amount of tokens from the caller
     * and send to the recipient.
     * @dev relayFills keeps track of pre-fee fill amounts as a convenience to relayers who want to specify round
     * numbers for the maxTokensToSend parameter or convenient numbers like 100 (i.e. relayers who will fully
     * fill any relay up to 100 tokens, and partial fill with 100 tokens for larger relays).
     * @dev Caller must approve this contract to transfer up to maxTokensToSend of the relayData.destinationToken.
     * The amount to be sent might end up less if there is insufficient relay amount remaining to be sent.
     */
    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _fillRelay(RelayExecution memory relayExecution) internal returns (uint256 fillAmountPreFees) {
        RelayData memory relayData = relayExecution.relay;
        // We limit the relay fees to prevent the user spending all their funds on fees. Note that 0.5e18 (i.e. 50%)
        // fees are just magic numbers. The important point is to prevent the total fee from being 100%, otherwise
        // computing the amount pre fees runs into divide-by-0 issues.
        require(
            SignedMath.abs(relayExecution.updatedRelayerFeePct) < 0.5e18 &&
                SignedMath.abs(relayData.realizedLpFeePct) < 0.5e18,
            "invalid fees"
        );

        require(relayData.amount <= MAX_TRANSFER_SIZE, "Amount too large");

        // Check that the relay has not already been completely filled. Note that the relays mapping will point to
        // the amount filled so far for a particular relayHash, so this will start at 0 and increment with each fill.
        require(DEPRECATED_relayFills[relayExecution.relayHash] < relayData.amount, "relay filled");

        // Derive the amount of the relay filled if the caller wants to send exactly maxTokensToSend tokens to
        // the recipient. For example, if the user wants to send 10 tokens to the recipient, the full relay amount
        // is 100, and the fee %'s total 5%, then this computation would return ~10.5, meaning that to fill 10.5/100
        // of the full relay size, the caller would need to send 10 tokens to the user.
        // This is equivalent to the amount to be sent by the relayer before fees have been taken out.
        fillAmountPreFees = _computeAmountPreFees(
            relayExecution.maxTokensToSend,
            (relayData.realizedLpFeePct + relayExecution.updatedRelayerFeePct)
        );
        // If fill amount minus fees, which is possible with small fill amounts and negative fees, then
        // revert.
        require(fillAmountPreFees > 0, "fill amount pre fees is 0");

        // If user's specified max amount to send is greater than the amount of the relay remaining pre-fees,
        // we'll pull exactly enough tokens to complete the relay.
        uint256 amountRemainingInRelay = relayData.amount - DEPRECATED_relayFills[relayExecution.relayHash];
        if (amountRemainingInRelay < fillAmountPreFees) {
            fillAmountPreFees = amountRemainingInRelay;
        }

        // Apply post-fees computation to amount that relayer will send to user. Rounding errors are possible
        // when computing fillAmountPreFees and then amountToSend, and we just want to enforce that
        // the error added to amountToSend is consistently applied to partial and full fills.
        uint256 amountToSend = _computeAmountPostFees(
            fillAmountPreFees,
            relayData.realizedLpFeePct + relayExecution.updatedRelayerFeePct
        );

        // This can only happen in a slow fill, where the contract is funding the relay.
        if (relayExecution.payoutAdjustmentPct != 0) {
            // If payoutAdjustmentPct is positive, then the recipient will receive more than the amount they
            // were originally expecting. If it is negative, then the recipient will receive less.
            // -1e18 is -100%. Because we cannot pay out negative values, that is the minimum.
            require(relayExecution.payoutAdjustmentPct >= -1e18, "payoutAdjustmentPct too small");

            // Allow the payout adjustment to go up to 1000% (i.e. 11x).
            // This is a sanity check to ensure the payouts do not grow too large via some sort of issue in bundle
            // construction.
            require(relayExecution.payoutAdjustmentPct <= 100e18, "payoutAdjustmentPct too large");

            // Note: since _computeAmountPostFees is typically intended for fees, the signage must be reversed.
            amountToSend = _computeAmountPostFees(amountToSend, -relayExecution.payoutAdjustmentPct);

            // Note: this error should never happen, since the maxTokensToSend is expected to be set much higher than
            // the amount, but it is here as a sanity check.
            require(amountToSend <= relayExecution.maxTokensToSend, "Somehow hit maxTokensToSend!");
        }

        // Since the first partial fill is used to update the fill counter for the entire refund amount, we don't have
        // a simple way to handle the case where follow-up partial fills take repayment on different chains. We'd
        // need a way to decrement the fill counter in this case (or increase deposit counter) to ensure that users
        // have adequate frontrunning protections.
        // Instead of adding complexity, we require that all partial fills set repayment chain equal to destination chain.
        // Note: .slowFill is checked because slow fills set repaymentChainId to 0.
        bool localRepayment = relayExecution.repaymentChainId == relayExecution.relay.destinationChainId;
        require(
            localRepayment || relayExecution.relay.amount == fillAmountPreFees || relayExecution.slowFill,
            "invalid repayment chain"
        );

        // relayFills keeps track of pre-fee fill amounts as a convenience to relayers who want to specify round
        // numbers for the maxTokensToSend parameter or convenient numbers like 100 (i.e. relayers who will fully
        // fill any relay up to 100 tokens, and partial fill with 100 tokens for larger relays).
        DEPRECATED_relayFills[relayExecution.relayHash] += fillAmountPreFees;

        // If relayer and receiver are the same address, there is no need to do any transfer, as it would result in no
        // net movement of funds.
        // Note: this is important because it means that relayers can intentionally self-relay in a capital efficient
        // way (no need to have funds on the destination).
        // If this is a slow fill, we can't exit early since we still need to send funds out of this contract
        // since there is no "relayer".
        if (msg.sender == relayExecution.updatedRecipient && !relayExecution.slowFill) return fillAmountPreFees;

        // If relay token is wrappedNativeToken then unwrap and send native token.
        if (relayData.destinationToken == address(wrappedNativeToken)) {
            // Note: useContractFunds is True if we want to send funds to the recipient directly out of this contract,
            // otherwise we expect the caller to send funds to the recipient. If useContractFunds is True and the
            // recipient wants wrappedNativeToken, then we can assume that wrappedNativeToken is already in the
            // contract, otherwise we'll need the user to send wrappedNativeToken to this contract. Regardless, we'll
            // need to unwrap it to native token before sending to the user.
            if (!relayExecution.slowFill)
                IERC20Upgradeable(relayData.destinationToken).safeTransferFrom(msg.sender, address(this), amountToSend);
            _unwrapwrappedNativeTokenTo(payable(relayExecution.updatedRecipient), amountToSend);
            // Else, this is a normal ERC20 token. Send to recipient.
        } else {
            // Note: Similar to note above, send token directly from the contract to the user in the slow relay case.
            if (!relayExecution.slowFill)
                IERC20Upgradeable(relayData.destinationToken).safeTransferFrom(
                    msg.sender,
                    relayExecution.updatedRecipient,
                    amountToSend
                );
            else
                IERC20Upgradeable(relayData.destinationToken).safeTransfer(
                    relayExecution.updatedRecipient,
                    amountToSend
                );
        }

        if (relayExecution.updatedRecipient.isContract() && relayExecution.updatedMessage.length > 0) {
            AcrossMessageHandler(relayExecution.updatedRecipient).handleAcrossMessage(
                relayData.destinationToken,
                amountToSend,
                DEPRECATED_relayFills[relayExecution.relayHash] >= relayData.amount,
                msg.sender,
                relayExecution.updatedMessage
            );
        }
    }

    // @param relayer: relayer who is actually credited as filling this deposit. Can be different from
    // exclusiveRelayer if passed exclusivityDeadline or if slow fill.
    function _fillRelayV3(
        V3RelayExecutionParams memory relayExecution,
        address relayer,
        bool isSlowFill
    ) internal {
        V3RelayData memory relayData = relayExecution.relay;

        if (relayData.fillDeadline < getCurrentTime()) revert ExpiredFillDeadline();

        bytes32 relayHash = relayExecution.relayHash;

        // If a slow fill for this fill was requested then the relayFills value for this hash will be
        // FillStatus.RequestedSlowFill. Therefore, if this is the status, then this fast fill
        // will be replacing the slow fill. If this is a slow fill execution, then the following variable
        // is trivially true. We'll emit this value in the FilledRelay
        // event to assist the Dataworker in knowing when to return funds back to the HubPool that can no longer
        // be used for a slow fill execution.
        FillType fillType = isSlowFill
            ? FillType.SlowFill
            : (
                // The following is true if this is a fast fill that was sent after a slow fill request.
                fillStatuses[relayExecution.relayHash] == uint256(FillStatus.RequestedSlowFill)
                    ? FillType.ReplacedSlowFill
                    : FillType.FastFill
            );

        // @dev This function doesn't support partial fills. Therefore, we associate the relay hash with
        // an enum tracking its fill status. All filled relays, whether slow or fast fills, are set to the Filled
        // status. However, we also use this slot to track whether this fill had a slow fill requested. Therefore
        // we can include a bool in the FilledRelay event making it easy for the dataworker to compute if this
        // fill was a fast fill that replaced a slow fill and therefore this SpokePool has excess funds that it
        // needs to send back to the HubPool.
        if (fillStatuses[relayHash] == uint256(FillStatus.Filled)) revert RelayFilled();
        fillStatuses[relayHash] = uint256(FillStatus.Filled);

        // @dev Before returning early, emit events to assist the dataworker in being able to know which fills were
        // successful.
        emit FilledV3Relay(
            relayData.inputToken,
            relayData.outputToken,
            relayData.inputAmount,
            relayData.outputAmount,
            relayExecution.repaymentChainId,
            relayData.originChainId,
            relayData.depositId,
            relayData.fillDeadline,
            relayData.exclusivityDeadline,
            relayData.exclusiveRelayer,
            relayer,
            relayData.depositor,
            relayData.recipient,
            relayData.message,
            V3RelayExecutionEventInfo({
                updatedRecipient: relayExecution.updatedRecipient,
                updatedMessage: relayExecution.updatedMessage,
                updatedOutputAmount: relayExecution.updatedOutputAmount,
                fillType: fillType
            })
        );

        // If relayer and receiver are the same address, there is no need to do any transfer, as it would result in no
        // net movement of funds.
        // Note: this is important because it means that relayers can intentionally self-relay in a capital efficient
        // way (no need to have funds on the destination).
        // If this is a slow fill, we can't exit early since we still need to send funds out of this contract
        // since there is no "relayer".
        address recipientToSend = relayExecution.updatedRecipient;

        if (msg.sender == recipientToSend && !isSlowFill) return;

        // If relay token is wrappedNativeToken then unwrap and send native token.
        address outputToken = relayData.outputToken;
        uint256 amountToSend = relayExecution.updatedOutputAmount;
        if (outputToken == address(wrappedNativeToken)) {
            // Note: useContractFunds is True if we want to send funds to the recipient directly out of this contract,
            // otherwise we expect the caller to send funds to the recipient. If useContractFunds is True and the
            // recipient wants wrappedNativeToken, then we can assume that wrappedNativeToken is already in the
            // contract, otherwise we'll need the user to send wrappedNativeToken to this contract. Regardless, we'll
            // need to unwrap it to native token before sending to the user.
            if (!isSlowFill) IERC20Upgradeable(outputToken).safeTransferFrom(msg.sender, address(this), amountToSend);
            _unwrapwrappedNativeTokenTo(payable(recipientToSend), amountToSend);
            // Else, this is a normal ERC20 token. Send to recipient.
        } else {
            // Note: Similar to note above, send token directly from the contract to the user in the slow relay case.
            if (!isSlowFill) IERC20Upgradeable(outputToken).safeTransferFrom(msg.sender, recipientToSend, amountToSend);
            else IERC20Upgradeable(outputToken).safeTransfer(recipientToSend, amountToSend);
        }

        bytes memory updatedMessage = relayExecution.updatedMessage;
        if (recipientToSend.isContract() && updatedMessage.length > 0) {
            AcrossMessageHandler(recipientToSend).handleV3AcrossMessage(
                outputToken,
                amountToSend,
                msg.sender,
                updatedMessage
            );
        }
    }

    /// @custom:audit FOLLOWING FUNCTION TO BE DEPRECATED
    function _emitFillRelay(RelayExecution memory relayExecution, uint256 fillAmountPreFees) internal {
        RelayExecutionInfo memory relayExecutionInfo = RelayExecutionInfo({
            relayerFeePct: relayExecution.updatedRelayerFeePct,
            recipient: relayExecution.updatedRecipient,
            message: relayExecution.updatedMessage,
            isSlowRelay: relayExecution.slowFill,
            payoutAdjustmentPct: relayExecution.payoutAdjustmentPct
        });

        emit FilledRelay(
            relayExecution.relay.amount,
            DEPRECATED_relayFills[relayExecution.relayHash],
            fillAmountPreFees,
            relayExecution.repaymentChainId,
            relayExecution.relay.originChainId,
            relayExecution.relay.destinationChainId,
            relayExecution.relay.relayerFeePct,
            relayExecution.relay.realizedLpFeePct,
            relayExecution.relay.depositId,
            relayExecution.relay.destinationToken,
            msg.sender,
            relayExecution.relay.depositor,
            relayExecution.relay.recipient,
            relayExecution.relay.message,
            relayExecutionInfo
        );
    }

    // Implementing contract needs to override this to ensure that only the appropriate cross chain admin can execute
    // certain admin functions. For L2 contracts, the cross chain admin refers to some L1 address or contract, and for
    // L1, this would just be the same admin of the HubPool.
    function _requireAdminSender() internal virtual;

    // Added to enable the this contract to receive native token (ETH). Used when unwrapping wrappedNativeToken.
    receive() external payable {}

    // Reserve storage slots for future versions of this base contract to add state variables without
    // affecting the storage layout of child contracts. Decrement the size of __gap whenever state variables
    // are added. This is at bottom of contract to make sure it's always at the end of storage.
    uint256[999] private __gap;
}

// SPDX-License-Identifier: AGPL-3.0

pragma solidity 0.8.20;

import "./interfaces/IPolygonRollupManager.sol";
import "./interfaces/IPolygonZkEVMGlobalExitRootV2.sol";
import "../interfaces/IPolygonZkEVMBridge.sol";
import "./interfaces/IPolygonRollupBase.sol";
import "../interfaces/IVerifierRollup.sol";
import "../lib/EmergencyManager.sol";
import "@openzeppelin/contracts-upgradeable/token/ERC20/utils/SafeERC20Upgradeable.sol";
import "./lib/PolygonTransparentProxy.sol";
import "./lib/PolygonAccessControlUpgradeable.sol";
import "./lib/LegacyZKEVMStateVariables.sol";
import "./consensus/zkEVM/PolygonZkEVMExistentEtrog.sol";
import "./lib/PolygonConstantsBase.sol";

/**
 * Contract responsible for managing rollups and the verification of their batches.
 * This contract will create and update rollups and store all the hashed sequenced data from them.
 * The logic for sequence batches is moved to the `consensus` contracts, while the verification of all of
 * them will be done in this one. In this way, the proof aggregation of the rollups will be easier on a close future.
 */
contract PolygonRollupManager is
    PolygonAccessControlUpgradeable,
    EmergencyManager,
    LegacyZKEVMStateVariables,
    PolygonConstantsBase,
    IPolygonRollupManager
{
    //using SafeERC20Upgradeable for IERC20Upgradeable;

    /**
     * @notice Struct which to store the rollup type data
     * @param consensusImplementation Consensus implementation ( contains the consensus logic for the transaparent proxy)
     * @param verifier verifier
     * @param forkID fork ID
     * @param rollupCompatibilityID Rollup compatibility ID, to check upgradability between rollup types
     * @param obsolete Indicates if the rollup type is obsolete
     * @param genesis Genesis block of the rollup, note that will only be used on creating new rollups, not upgrade them
     */
    struct RollupType {
        address consensusImplementation;
        IVerifierRollup verifier;
        uint64 forkID;
        uint8 rollupCompatibilityID;
        bool obsolete;
        bytes32 genesis;
    }

    /**
     * @notice Struct which to store the rollup data of each chain
     * @param rollupContract Rollup consensus contract, which manages everything
     * related to sequencing transactions
     * @param chainID Chain ID of the rollup
     * @param verifier Verifier contract
     * @param forkID ForkID of the rollup
     * @param batchNumToStateRoot State root mapping
     * @param sequencedBatches Queue of batches that defines the virtual state
     * @param pendingStateTransitions Pending state mapping
     * @param lastLocalExitRoot Last exit root verified, used for compute the rollupExitRoot
     * @param lastBatchSequenced Last batch sent by the consensus contract
     * @param lastVerifiedBatch Last batch verified
     * @param lastPendingState Last pending state
     * @param lastPendingStateConsolidated Last pending state consolidated
     * @param lastVerifiedBatchBeforeUpgrade Last batch verified before the last upgrade
     * @param rollupTypeID Rollup type ID, can be 0 if it was added as an existing rollup
     * @param rollupCompatibilityID Rollup ID used for compatibility checks when upgrading
     */
    struct RollupData {
        IPolygonRollupBase rollupContract;
        uint64 chainID;
        IVerifierRollup verifier;
        uint64 forkID;
        mapping(uint64 batchNum => bytes32) batchNumToStateRoot;
        mapping(uint64 batchNum => SequencedBatchData) sequencedBatches;
        mapping(uint256 pendingStateNum => PendingState) pendingStateTransitions;
        bytes32 lastLocalExitRoot;
        uint64 lastBatchSequenced;
        uint64 lastVerifiedBatch;
        uint64 lastPendingState;
        uint64 lastPendingStateConsolidated;
        uint64 lastVerifiedBatchBeforeUpgrade;
        uint64 rollupTypeID;
        uint8 rollupCompatibilityID;
    }

    // Modulus zkSNARK
    uint256 internal constant _RFIELD =
        21888242871839275222246405745257275088548364400416034343698204186575808495617;

    // Max batch multiplier per verification
    uint256 internal constant _MAX_BATCH_MULTIPLIER = 12;

    // Max batch fee value
    uint256 internal constant _MAX_BATCH_FEE = 1000 ether;

    // Min value batch fee
    uint256 internal constant _MIN_BATCH_FEE = 1 gwei;

    // Goldilocks prime field
    uint256 internal constant _GOLDILOCKS_PRIME_FIELD = 0xFFFFFFFF00000001; // 2 ** 64 - 2 ** 32 + 1

    // Max uint64
    uint256 internal constant _MAX_UINT_64 = type(uint64).max; // 0xFFFFFFFFFFFFFFFF

    // Exit merkle tree levels
    uint256 internal constant _EXIT_TREE_DEPTH = 32;

    // Roles

    // Be able to add a new rollup type
    bytes32 internal constant _ADD_ROLLUP_TYPE_ROLE =
        keccak256("ADD_ROLLUP_TYPE_ROLE");

    // Be able to obsolete a rollup type, which means that new rollups cannot use this type
    bytes32 internal constant _OBSOLETE_ROLLUP_TYPE_ROLE =
        keccak256("OBSOLETE_ROLLUP_TYPE_ROLE");

    // Be able to create a new rollup using a rollup type
    bytes32 internal constant _CREATE_ROLLUP_ROLE =
        keccak256("CREATE_ROLLUP_ROLE");

    // Be able to create a new rollup which does not have to follow any rollup type.
    // Also sets the genesis block for that network
    bytes32 internal constant _ADD_EXISTING_ROLLUP_ROLE =
        keccak256("ADD_EXISTING_ROLLUP_ROLE");

    // Be able to update a rollup to a new rollup type that it's compatible
    bytes32 internal constant _UPDATE_ROLLUP_ROLE =
        keccak256("UPDATE_ROLLUP_ROLE");

    // Be able to that has priority to verify batches and consolidates the state instantly
    bytes32 internal constant _TRUSTED_AGGREGATOR_ROLE =
        keccak256("TRUSTED_AGGREGATOR_ROLE");

    // Be able to set the trusted aggregator address
    bytes32 internal constant _TRUSTED_AGGREGATOR_ROLE_ADMIN =
        keccak256("TRUSTED_AGGREGATOR_ROLE_ADMIN");

    // Be able to tweak parameters
    bytes32 internal constant _TWEAK_PARAMETERS_ROLE =
        keccak256("TWEAK_PARAMETERS_ROLE");

    // Be able to set the current batch fee
    bytes32 internal constant _SET_FEE_ROLE = keccak256("SET_FEE_ROLE");

    // Be able to stop the emergency state
    bytes32 internal constant _STOP_EMERGENCY_ROLE =
        keccak256("STOP_EMERGENCY_ROLE");

    // Be able to activate the emergency state without any further condition
    bytes32 internal constant _EMERGENCY_COUNCIL_ROLE =
        keccak256("EMERGENCY_COUNCIL_ROLE");

    // Be able to set the emergency council address
    bytes32 internal constant _EMERGENCY_COUNCIL_ADMIN =
        keccak256("EMERGENCY_COUNCIL_ADMIN");

    // Global Exit Root address
    IPolygonZkEVMGlobalExitRootV2 public immutable globalExitRootManager;

    // PolygonZkEVM Bridge Address
    IPolygonZkEVMBridge public immutable bridgeAddress;

    // POL token address
    IERC20Upgradeable public immutable pol;

    // Number of rollup types added, every new type will be assigned sequencially a new ID
    uint32 public rollupTypeCount;

    // Rollup type mapping
    mapping(uint32 rollupTypeID => RollupType) public rollupTypeMap;

    // Number of rollups added, every new rollup will be assigned sequencially a new ID
    uint32 public rollupCount;

    // Rollups ID mapping
    mapping(uint32 rollupID => RollupData) public rollupIDToRollupData;

    // Rollups address mapping
    mapping(address rollupAddress => uint32 rollupID) public rollupAddressToID;

    // Chain ID mapping for nullifying
    // note we will take care to avoid that current known chainIDs are not reused in our networks (example: 1)
    mapping(uint64 chainID => uint32 rollupID) public chainIDToRollupID;

    // Total sequenced batches across all rollups
    uint64 public totalSequencedBatches;

    // Total verified batches across all rollups
    uint64 public totalVerifiedBatches;

    // Last timestamp when an aggregation happen
    uint64 public lastAggregationTimestamp;

    // Trusted aggregator timeout, if a sequence is not verified in this time frame,
    // everyone can verify that sequence
    uint64 public trustedAggregatorTimeout;

    // Once a pending state exceeds this timeout it can be consolidated
    uint64 public pendingStateTimeout;

    // Time target of the verification of a batch
    // Adaptively the batchFee will be updated to achieve this target
    uint64 public verifyBatchTimeTarget;

    // Batch fee multiplier with 3 decimals that goes from 1000 - 1023
    uint16 public multiplierBatchFee;

    // Current POL fee per batch sequenced
    // note This variable is internal, since the view function getBatchFee is likely to be upgraded
    uint256 internal _batchFee;

    // Timestamp when the last emergency state was deactivated
    uint64 public lastDeactivatedEmergencyStateTimestamp;

    /**
     * @dev Emitted when a new rollup type is added
     */
    event AddNewRollupType(
        uint32 indexed rollupTypeID,
        address consensusImplementation,
        address verifier,
        uint64 forkID,
        uint8 rollupCompatibilityID,
        bytes32 genesis,
        string description
    );

    /**
     * @dev Emitted when a a rolup type is obsoleted
     */
    event ObsoleteRollupType(uint32 indexed rollupTypeID);

    /**
     * @dev Emitted when a new rollup is created based on a rollupType
     */
    event CreateNewRollup(
        uint32 indexed rollupID,
        uint32 rollupTypeID,
        address rollupAddress,
        uint64 chainID,
        address gasTokenAddress
    );

    /**
     * @dev Emitted when an existing rollup is added
     */
    event AddExistingRollup(
        uint32 indexed rollupID,
        uint64 forkID,
        address rollupAddress,
        uint64 chainID,
        uint8 rollupCompatibilityID,
        uint64 lastVerifiedBatchBeforeUpgrade
    );

    /**
     * @dev Emitted when a rollup is udpated
     */
    event UpdateRollup(
        uint32 indexed rollupID,
        uint32 newRollupTypeID,
        uint64 lastVerifiedBatchBeforeUpgrade
    );

    /**
     * @dev Emitted when a new verifier is added
     */
    event OnSequenceBatches(uint32 indexed rollupID, uint64 lastBatchSequenced);

    /**
     * @dev Emitted when an aggregator verifies batches
     */
    event VerifyBatches(
        uint32 indexed rollupID,
        uint64 numBatch,
        bytes32 stateRoot,
        bytes32 exitRoot,
        address indexed aggregator
    );

    /**
     * @dev Emitted when the trusted aggregator verifies batches
     */
    event VerifyBatchesTrustedAggregator(
        uint32 indexed rollupID,
        uint64 numBatch,
        bytes32 stateRoot,
        bytes32 exitRoot,
        address indexed aggregator
    );

    /**
     * @dev Emitted when pending state is consolidated
     */
    event ConsolidatePendingState(
        uint32 indexed rollupID,
        uint64 numBatch,
        bytes32 stateRoot,
        bytes32 exitRoot,
        uint64 pendingStateNum
    );

    /**
     * @dev Emitted when is proved a different state given the same batches
     */
    event ProveNonDeterministicPendingState(
        bytes32 storedStateRoot,
        bytes32 provedStateRoot
    );

    /**
     * @dev Emitted when the trusted aggregator overrides pending state
     */
    event OverridePendingState(
        uint32 indexed rollupID,
        uint64 numBatch,
        bytes32 stateRoot,
        bytes32 exitRoot,
        address aggregator
    );

    /**
     * @dev Emitted when is updated the trusted aggregator timeout
     */
    event SetTrustedAggregatorTimeout(uint64 newTrustedAggregatorTimeout);

    /**
     * @dev Emitted when is updated the pending state timeout
     */
    event SetPendingStateTimeout(uint64 newPendingStateTimeout);

    /**
     * @dev Emitted when is updated the multiplier batch fee
     */
    event SetMultiplierBatchFee(uint16 newMultiplierBatchFee);

    /**
     * @dev Emitted when is updated the verify batch timeout
     */
    event SetVerifyBatchTimeTarget(uint64 newVerifyBatchTimeTarget);

    /**
     * @dev Emitted when is updated the trusted aggregator address
     */
    event SetTrustedAggregator(address newTrustedAggregator);

    /**
     * @dev Emitted when is updated the batch fee
     */
    event SetBatchFee(uint256 newBatchFee);

    /**
     * @param _globalExitRootManager Global exit root manager address
     * @param _pol POL token address
     * @param _bridgeAddress Bridge address
     */
    constructor(
        IPolygonZkEVMGlobalExitRootV2 _globalExitRootManager,
        IERC20Upgradeable _pol,
        IPolygonZkEVMBridge _bridgeAddress
    ) {
        globalExitRootManager = _globalExitRootManager;
        pol = _pol;
        bridgeAddress = _bridgeAddress;

        // Disable initalizers on the implementation following the best practices
        _disableInitializers();
    }

    /**
     * @param trustedAggregator Trusted aggregator address
     * @param _pendingStateTimeout Pending state timeout
     * @param _trustedAggregatorTimeout Trusted aggregator timeout
     * @param admin Admin of the rollup manager
     * @param timelock Timelock address
     * @param emergencyCouncil Emergency council address
     * @param polygonZkEVM New deployed Polygon zkEVM which will be initialized wiht previous values
     * @param zkEVMVerifier Verifier of the new zkEVM deployed
     * @param zkEVMForkID Fork id of the new zkEVM deployed
     * @param zkEVMChainID Chain id of the new zkEVM deployed
     */
    function initialize(
        address trustedAggregator,
        uint64 _pendingStateTimeout,
        uint64 _trustedAggregatorTimeout,
        address admin,
        address timelock,
        address emergencyCouncil,
        PolygonZkEVMExistentEtrog polygonZkEVM,
        IVerifierRollup zkEVMVerifier,
        uint64 zkEVMForkID,
        uint64 zkEVMChainID
    ) external virtual reinitializer(2) {
        pendingStateTimeout = _pendingStateTimeout;
        trustedAggregatorTimeout = _trustedAggregatorTimeout;

        // Constant deployment variables
        _batchFee = 0.1 ether; // 0.1 POL
        verifyBatchTimeTarget = 30 minutes;
        multiplierBatchFee = 1002;

        // Initialize OZ contracts
        __AccessControl_init();

        // setup roles

        // trusted aggregator role
        _setupRole(_TRUSTED_AGGREGATOR_ROLE, trustedAggregator);

        // Timelock roles
        _setupRole(DEFAULT_ADMIN_ROLE, timelock);
        _setupRole(_ADD_ROLLUP_TYPE_ROLE, timelock);
        _setupRole(_ADD_EXISTING_ROLLUP_ROLE, timelock);

        // note even this role can only update to an already added verifier/consensus
        // Could break the compatibility of them, changing the virtual state
        _setupRole(_UPDATE_ROLLUP_ROLE, timelock);

        // admin roles
        _setupRole(_OBSOLETE_ROLLUP_TYPE_ROLE, admin);
        _setupRole(_CREATE_ROLLUP_ROLE, admin);
        _setupRole(_STOP_EMERGENCY_ROLE, admin);
        _setupRole(_TWEAK_PARAMETERS_ROLE, admin);

        // admin should be able to update the trusted aggregator address
        _setRoleAdmin(_TRUSTED_AGGREGATOR_ROLE, _TRUSTED_AGGREGATOR_ROLE_ADMIN);
        _setupRole(_TRUSTED_AGGREGATOR_ROLE_ADMIN, admin);
        _setupRole(_SET_FEE_ROLE, admin);

        // Emergency council roles
        _setRoleAdmin(_EMERGENCY_COUNCIL_ROLE, _EMERGENCY_COUNCIL_ADMIN);
        _setupRole(_EMERGENCY_COUNCIL_ROLE, emergencyCouncil);
        _setupRole(_EMERGENCY_COUNCIL_ADMIN, emergencyCouncil);

        // Check last verified batch
        uint64 zkEVMLastBatchSequenced = _legacylastBatchSequenced;
        uint64 zkEVMLastVerifiedBatch = _legacyLastVerifiedBatch;
        if (zkEVMLastBatchSequenced != zkEVMLastVerifiedBatch) {
            revert AllzkEVMSequencedBatchesMustBeVerified();
        }

        // Initialize current zkEVM
        RollupData storage currentZkEVM = _addExistingRollup(
            IPolygonRollupBase(polygonZkEVM),
            zkEVMVerifier,
            zkEVMForkID,
            zkEVMChainID,
            0, // Rollup compatibility ID is 0
            _legacyLastVerifiedBatch
        );

        // Copy variables from legacy
        currentZkEVM.batchNumToStateRoot[
            zkEVMLastVerifiedBatch
        ] = _legacyBatchNumToStateRoot[zkEVMLastVerifiedBatch];

        // note previousLastBatchSequenced of the SequencedBatchData will be inconsistent,
        // since there will not be a previous sequence stored in the sequence mapping.
        // However since lastVerifiedBatch is equal to the lastBatchSequenced
        // won't affect in any case
        currentZkEVM.sequencedBatches[
            zkEVMLastBatchSequenced
        ] = _legacySequencedBatches[zkEVMLastBatchSequenced];

        currentZkEVM.lastBatchSequenced = zkEVMLastBatchSequenced;
        currentZkEVM.lastVerifiedBatch = zkEVMLastVerifiedBatch;
        currentZkEVM.lastVerifiedBatchBeforeUpgrade = zkEVMLastVerifiedBatch;
        // rollupType and rollupCompatibilityID will be both 0

        // Initialize polygon zkevm
        polygonZkEVM.initializeUpgrade(
            _legacyAdmin,
            _legacyTrustedSequencer,
            _legacyTrustedSequencerURL,
            _legacyNetworkName,
            _legacySequencedBatches[zkEVMLastBatchSequenced].accInputHash
        );
    }

    ///////////////////////////////////////
    // Rollups management functions
    ///////////////////////////////////////

    /**
     * @notice Add a new rollup type
     * @param consensusImplementation Consensus implementation
     * @param verifier Verifier address
     * @param forkID ForkID of the verifier
     * @param genesis Genesis block of the rollup
     * @param description Description of the rollup type
     */
    function addNewRollupType(
        address consensusImplementation,
        IVerifierRollup verifier,
        uint64 forkID,
        uint8 rollupCompatibilityID,
        bytes32 genesis,
        string memory description
    ) external onlyRole(_ADD_ROLLUP_TYPE_ROLE) {
        uint32 rollupTypeID = ++rollupTypeCount;

        rollupTypeMap[rollupTypeID] = RollupType({
            consensusImplementation: consensusImplementation,
            verifier: verifier,
            forkID: forkID,
            rollupCompatibilityID: rollupCompatibilityID,
            obsolete: false,
            genesis: genesis
        });

        emit AddNewRollupType(
            rollupTypeID,
            consensusImplementation,
            address(verifier),
            forkID,
            rollupCompatibilityID,
            genesis,
            description
        );
    }

    /**
     * @notice Obsolete Rollup type
     * @param rollupTypeID Rollup type to obsolete
     */
    function obsoleteRollupType(
        uint32 rollupTypeID
    ) external onlyRole(_OBSOLETE_ROLLUP_TYPE_ROLE) {
        // Check that rollup type exists
        if (rollupTypeID == 0 || rollupTypeID > rollupTypeCount) {
            revert RollupTypeDoesNotExist();
        }

        // Check rollup type is not obsolete
        RollupType storage currentRollupType = rollupTypeMap[rollupTypeID];
        if (currentRollupType.obsolete == true) {
            revert RollupTypeObsolete();
        }

        currentRollupType.obsolete = true;

        emit ObsoleteRollupType(rollupTypeID);
    }

    /**
     * @notice Create a new rollup
     * @param rollupTypeID Rollup type to deploy
     * @param chainID ChainID of the rollup, must be a new one
     * @param admin Admin of the new created rollup
     * @param sequencer Sequencer of the new created rollup
     * @param gasTokenAddress Indicates the token address that will be used to pay gas fees in the new rollup
     * Note if a wrapped token of the bridge is used, the original network and address of this wrapped will be used instead
     * @param sequencerURL Sequencer URL of the new created rollup
     * @param networkName Network name of the new created rollup
     */
    function createNewRollup(
        uint32 rollupTypeID,
        uint64 chainID,
        address admin,
        address sequencer,
        address gasTokenAddress,
        string memory sequencerURL,
        string memory networkName
    ) external onlyRole(_CREATE_ROLLUP_ROLE) {
        // Check that rollup type exists
        if (rollupTypeID == 0 || rollupTypeID > rollupTypeCount) {
            revert RollupTypeDoesNotExist();
        }

        // Check rollup type is not obsolete
        RollupType storage rollupType = rollupTypeMap[rollupTypeID];
        if (rollupType.obsolete == true) {
            revert RollupTypeObsolete();
        }

        // Check chainID nullifier
        if (chainIDToRollupID[chainID] != 0) {
            revert ChainIDAlreadyExist();
        }

        // Create a new Rollup, using a transparent proxy pattern
        // Consensus will be the implementation, and this contract the admin
        uint32 rollupID = ++rollupCount;
        address rollupAddress = address(
            new PolygonTransparentProxy(
                rollupType.consensusImplementation,
                address(this),
                new bytes(0)
            )
        );

        // Set chainID nullifier
        chainIDToRollupID[chainID] = rollupID;

        // Store rollup data
        rollupAddressToID[rollupAddress] = rollupID;

        RollupData storage rollup = rollupIDToRollupData[rollupID];

        rollup.rollupContract = IPolygonRollupBase(rollupAddress);
        rollup.forkID = rollupType.forkID;
        rollup.verifier = rollupType.verifier;
        rollup.chainID = chainID;
        rollup.batchNumToStateRoot[0] = rollupType.genesis;
        rollup.rollupTypeID = rollupTypeID;
        rollup.rollupCompatibilityID = rollupType.rollupCompatibilityID;

        emit CreateNewRollup(
            rollupID,
            rollupTypeID,
            rollupAddress,
            chainID,
            gasTokenAddress
        );

        // Initialize new rollup
        IPolygonRollupBase(rollupAddress).initialize(
            admin,
            sequencer,
            rollupID,
            gasTokenAddress,
            sequencerURL,
            networkName
        );
    }

    /**
     * @notice Add an already deployed rollup
     * note that this rollup does not follow any rollupType
     * @param rollupAddress Rollup address
     * @param verifier Verifier address, must be added before
     * @param forkID Fork id of the added rollup
     * @param chainID Chain id of the added rollup
     * @param genesis Genesis block for this rollup
     * @param rollupCompatibilityID Compatibility ID for the added rollup
     */
    function addExistingRollup(
        IPolygonRollupBase rollupAddress,
        IVerifierRollup verifier,
        uint64 forkID,
        uint64 chainID,
        bytes32 genesis,
        uint8 rollupCompatibilityID
    ) external onlyRole(_ADD_EXISTING_ROLLUP_ROLE) {
        // Check chainID nullifier
        if (chainIDToRollupID[chainID] != 0) {
            revert ChainIDAlreadyExist();
        }

        // Check if rollup address was already added
        if (rollupAddressToID[address(rollupAddress)] != 0) {
            revert RollupAddressAlreadyExist();
        }

        RollupData storage rollup = _addExistingRollup(
            rollupAddress,
            verifier,
            forkID,
            chainID,
            rollupCompatibilityID,
            0 // last verified batch it's always 0
        );
        rollup.batchNumToStateRoot[0] = genesis;
    }

    /**
     * @notice Add an already deployed rollup
     * note that this rollup does not follow any rollupType
     * @param rollupAddress Rollup address
     * @param verifier Verifier address, must be added before
     * @param forkID Fork id of the added rollup
     * @param chainID Chain id of the added rollup
     * @param rollupCompatibilityID Compatibility ID for the added rollup
     * @param lastVerifiedBatch Last verified batch before adding the rollup
     */
    function _addExistingRollup(
        IPolygonRollupBase rollupAddress,
        IVerifierRollup verifier,
        uint64 forkID,
        uint64 chainID,
        uint8 rollupCompatibilityID,
        uint64 lastVerifiedBatch
    ) internal returns (RollupData storage rollup) {
        uint32 rollupID = ++rollupCount;

        // Set chainID nullifier
        chainIDToRollupID[chainID] = rollupID;

        // Store rollup data
        rollupAddressToID[address(rollupAddress)] = rollupID;

        rollup = rollupIDToRollupData[rollupID];
        rollup.rollupContract = rollupAddress;
        rollup.forkID = forkID;
        rollup.verifier = verifier;
        rollup.chainID = chainID;
        rollup.rollupCompatibilityID = rollupCompatibilityID;
        // rollup type is 0, since it does not follow any rollup type

        emit AddExistingRollup(
            rollupID,
            forkID,
            address(rollupAddress),
            chainID,
            rollupCompatibilityID,
            lastVerifiedBatch
        );
    }

    /**
     * @notice Upgrade an existing rollup
     * @param rollupContract Rollup consensus proxy address
     * @param newRollupTypeID New rolluptypeID to upgrade to
     * @param upgradeData Upgrade data
     */
    function updateRollup(
        ITransparentUpgradeableProxy rollupContract,
        uint32 newRollupTypeID,
        bytes calldata upgradeData
    ) external onlyRole(_UPDATE_ROLLUP_ROLE) {
        // Check that rollup type exists
        if (newRollupTypeID == 0 || newRollupTypeID > rollupTypeCount) {
            revert RollupTypeDoesNotExist();
        }

        // Check the rollup exists
        uint32 rollupID = rollupAddressToID[address(rollupContract)];
        if (rollupID == 0) {
            revert RollupMustExist();
        }

        RollupData storage rollup = rollupIDToRollupData[rollupID];

        // The update must be to a new rollup type
        if (rollup.rollupTypeID == newRollupTypeID) {
            revert UpdateToSameRollupTypeID();
        }

        RollupType storage newRollupType = rollupTypeMap[newRollupTypeID];

        // Check rollup type is not obsolete
        if (newRollupType.obsolete == true) {
            revert RollupTypeObsolete();
        }

        // Check compatibility of the rollups
        if (
            rollup.rollupCompatibilityID != newRollupType.rollupCompatibilityID
        ) {
            revert UpdateNotCompatible();
        }

        // Update rollup parameters
        rollup.verifier = newRollupType.verifier;
        rollup.forkID = newRollupType.forkID;
        rollup.rollupTypeID = newRollupTypeID;

        uint64 lastVerifiedBatch = getLastVerifiedBatch(rollupID);
        rollup.lastVerifiedBatchBeforeUpgrade = lastVerifiedBatch;

        // Upgrade rollup
        rollupContract.upgradeToAndCall(
            newRollupType.consensusImplementation,
            upgradeData
        );

        emit UpdateRollup(rollupID, newRollupTypeID, lastVerifiedBatch);
    }

    /////////////////////////////////////
    // Sequence/Verify batches functions
    ////////////////////////////////////

    /**
     * @notice Sequence batches, callback called by one of the consensus managed by this contract
     * @param newSequencedBatches Number of batches sequenced
     * @param newAccInputHash New accumulate input hash
     */
    function onSequenceBatches(
        uint64 newSequencedBatches,
        bytes32 newAccInputHash
    ) external ifNotEmergencyState returns (uint64) {
        // Check that the msg.sender is an added rollup
        uint32 rollupID = rollupAddressToID[msg.sender];
        if (rollupID == 0) {
            revert SenderMustBeRollup();
        }

        // This prevents overwritting sequencedBatches
        if (newSequencedBatches == 0) {
            revert MustSequenceSomeBatch();
        }

        RollupData storage rollup = rollupIDToRollupData[rollupID];

        // Update total sequence parameters
        totalSequencedBatches += newSequencedBatches;

        // Update sequenced batches of the current rollup
        uint64 previousLastBatchSequenced = rollup.lastBatchSequenced;
        uint64 newLastBatchSequenced = previousLastBatchSequenced +
            newSequencedBatches;

        rollup.lastBatchSequenced = newLastBatchSequenced;
        rollup.sequencedBatches[newLastBatchSequenced] = SequencedBatchData({
            accInputHash: newAccInputHash,
            sequencedTimestamp: uint64(block.timestamp),
            previousLastBatchSequenced: previousLastBatchSequenced
        });

        // Consolidate pending state if possible
        _tryConsolidatePendingState(rollup);

        emit OnSequenceBatches(rollupID, newLastBatchSequenced);

        return newLastBatchSequenced;
    }

    /**
     * @notice Allows an aggregator to verify multiple batches
     * @param rollupID Rollup identifier
     * @param pendingStateNum Init pending state, 0 if consolidated state is used
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot New local exit root once the batch is processed
     * @param newStateRoot New State root once the batch is processed
     * @param beneficiary Address that will receive the verification reward
     * @param proof Fflonk proof
     */
    function verifyBatches(
        uint32 rollupID,
        uint64 pendingStateNum,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 newStateRoot,
        address beneficiary,
        bytes32[24] calldata proof
    ) external ifNotEmergencyState {
        RollupData storage rollup = rollupIDToRollupData[rollupID];

        // Check if the trusted aggregator timeout expired,
        // Note that the sequencedBatches struct must exists for this finalNewBatch, if not newAccInputHash will be 0
        if (
            rollup.sequencedBatches[finalNewBatch].sequencedTimestamp +
                trustedAggregatorTimeout >
            block.timestamp
        ) {
            revert TrustedAggregatorTimeoutNotExpired();
        }

        if (finalNewBatch - initNumBatch > _MAX_VERIFY_BATCHES) {
            revert ExceedMaxVerifyBatches();
        }

        _verifyAndRewardBatches(
            rollup,
            pendingStateNum,
            initNumBatch,
            finalNewBatch,
            newLocalExitRoot,
            newStateRoot,
            beneficiary,
            proof
        );

        // Update batch fees
        _updateBatchFee(rollup, finalNewBatch);

        if (pendingStateTimeout == 0) {
            // Consolidate state
            rollup.lastVerifiedBatch = finalNewBatch;
            rollup.batchNumToStateRoot[finalNewBatch] = newStateRoot;
            rollup.lastLocalExitRoot = newLocalExitRoot;

            // Clean pending state if any
            if (rollup.lastPendingState > 0) {
                rollup.lastPendingState = 0;
                rollup.lastPendingStateConsolidated = 0;
            }

            // Interact with globalExitRootManager
            globalExitRootManager.updateExitRoot(getRollupExitRoot());
        } else {
            // Consolidate pending state if possible
            _tryConsolidatePendingState(rollup);

            // Update pending state
            rollup.lastPendingState++;
            rollup.pendingStateTransitions[
                rollup.lastPendingState
            ] = PendingState({
                timestamp: uint64(block.timestamp),
                lastVerifiedBatch: finalNewBatch,
                exitRoot: newLocalExitRoot,
                stateRoot: newStateRoot
            });
        }

        emit VerifyBatches(
            rollupID,
            finalNewBatch,
            newStateRoot,
            newLocalExitRoot,
            msg.sender
        );
    }

    /**
     * @notice Allows a trusted aggregator to verify multiple batches
     * @param rollupID Rollup identifier
     * @param pendingStateNum Init pending state, 0 if consolidated state is used
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot New local exit root once the batch is processed
     * @param newStateRoot New State root once the batch is processed
     * @param beneficiary Address that will receive the verification reward
     * @param proof Fflonk proof
     */
    function verifyBatchesTrustedAggregator(
        uint32 rollupID,
        uint64 pendingStateNum,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 newStateRoot,
        address beneficiary,
        bytes32[24] calldata proof
    ) external onlyRole(_TRUSTED_AGGREGATOR_ROLE) {
        RollupData storage rollup = rollupIDToRollupData[rollupID];

        _verifyAndRewardBatches(
            rollup,
            pendingStateNum,
            initNumBatch,
            finalNewBatch,
            newLocalExitRoot,
            newStateRoot,
            beneficiary,
            proof
        );

        // Consolidate state
        rollup.lastVerifiedBatch = finalNewBatch;
        rollup.batchNumToStateRoot[finalNewBatch] = newStateRoot;
        rollup.lastLocalExitRoot = newLocalExitRoot;

        // Clean pending state if any
        if (rollup.lastPendingState > 0) {
            rollup.lastPendingState = 0;
            rollup.lastPendingStateConsolidated = 0;
        }

        // Interact with globalExitRootManager
        globalExitRootManager.updateExitRoot(getRollupExitRoot());

        emit VerifyBatchesTrustedAggregator(
            rollupID,
            finalNewBatch,
            newStateRoot,
            newLocalExitRoot,
            msg.sender
        );
    }

    /**
     * @notice Verify and reward batches internal function
     * @param rollup Rollup Data storage pointer that will be used to the verification
     * @param pendingStateNum Init pending state, 0 if consolidated state is used
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot New local exit root once the batch is processed
     * @param newStateRoot New State root once the batch is processed
     * @param beneficiary Address that will receive the verification reward
     * @param proof Fflonk proof
     */
    function _verifyAndRewardBatches(
        RollupData storage rollup,
        uint64 pendingStateNum,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 newStateRoot,
        address beneficiary,
        bytes32[24] calldata proof
    ) internal virtual {
        bytes32 oldStateRoot;
        uint64 currentLastVerifiedBatch = _getLastVerifiedBatch(rollup);

        if (initNumBatch < rollup.lastVerifiedBatchBeforeUpgrade) {
            revert InitBatchMustMatchCurrentForkID();
        }

        // Use pending state if specified, otherwise use consolidated state
        if (pendingStateNum != 0) {
            // Check that pending state exist
            // Already consolidated pending states can be used aswell
            if (pendingStateNum > rollup.lastPendingState) {
                revert PendingStateDoesNotExist();
            }

            // Check choosen pending state
            PendingState storage currentPendingState = rollup
                .pendingStateTransitions[pendingStateNum];

            // Get oldStateRoot from pending batch
            oldStateRoot = currentPendingState.stateRoot;

            // Check initNumBatch matches the pending state
            if (initNumBatch != currentPendingState.lastVerifiedBatch) {
                revert InitNumBatchDoesNotMatchPendingState();
            }
        } else {
            // Use consolidated state
            oldStateRoot = rollup.batchNumToStateRoot[initNumBatch];

            if (oldStateRoot == bytes32(0)) {
                revert OldStateRootDoesNotExist();
            }

            // Check initNumBatch is inside the range, sanity check
            if (initNumBatch > currentLastVerifiedBatch) {
                revert InitNumBatchAboveLastVerifiedBatch();
            }
        }

        // Check final batch
        if (finalNewBatch <= currentLastVerifiedBatch) {
            revert FinalNumBatchBelowLastVerifiedBatch();
        }

        // Get snark bytes
        bytes memory snarkHashBytes = _getInputSnarkBytes(
            rollup,
            initNumBatch,
            finalNewBatch,
            newLocalExitRoot,
            oldStateRoot,
            newStateRoot
        );

        // Calulate the snark input
        uint256 inputSnark = uint256(sha256(snarkHashBytes)) % _RFIELD;

        // TODO(radomski): Lower does not work
        // Verify proof
        // if (!rollup.verifier.verifyProof(proof, [inputSnark])) {
        //     revert InvalidProof();
        // }

        // Pay POL rewards
        uint64 newVerifiedBatches = finalNewBatch - currentLastVerifiedBatch;

        pol.safeTransfer(
            beneficiary,
            calculateRewardPerBatch() * newVerifiedBatches
        );

        // Update aggregation parameters
        totalVerifiedBatches += newVerifiedBatches;
        lastAggregationTimestamp = uint64(block.timestamp);

        // Callback to the rollup address
        rollup.rollupContract.onVerifyBatches(
            finalNewBatch,
            newStateRoot,
            msg.sender
        );
    }

    /**
     * @notice Internal function to consolidate the state automatically once sequence or verify batches are called
     * It tries to consolidate the first and the middle pending state in the queue
     */
    function _tryConsolidatePendingState(RollupData storage rollup) internal {
        // Check if there's any state to consolidate
        if (rollup.lastPendingState > rollup.lastPendingStateConsolidated) {
            // Check if it's possible to consolidate the next pending state
            uint64 nextPendingState = rollup.lastPendingStateConsolidated + 1;
            if (_isPendingStateConsolidable(rollup, nextPendingState)) {
                // Check middle pending state ( binary search of 1 step)
                uint64 middlePendingState = nextPendingState +
                    (rollup.lastPendingState - nextPendingState) /
                    2;

                // Try to consolidate it, and if not, consolidate the nextPendingState
                if (_isPendingStateConsolidable(rollup, middlePendingState)) {
                    _consolidatePendingState(rollup, middlePendingState);
                } else {
                    _consolidatePendingState(rollup, nextPendingState);
                }
            }
        }
    }

    /**
     * @notice Allows to consolidate any pending state that has already exceed the pendingStateTimeout
     * Can be called by the trusted aggregator, which can consolidate any state without the timeout restrictions
     * @param rollupID Rollup identifier
     * @param pendingStateNum Pending state to consolidate
     */
    function consolidatePendingState(
        uint32 rollupID,
        uint64 pendingStateNum
    ) external {
        RollupData storage rollup = rollupIDToRollupData[rollupID];
        // Check if pending state can be consolidated
        // If trusted aggregator is the sender, do not check the timeout or the emergency state
        if (!hasRole(_TRUSTED_AGGREGATOR_ROLE, msg.sender)) {
            if (isEmergencyState) {
                revert OnlyNotEmergencyState();
            }

            if (!_isPendingStateConsolidable(rollup, pendingStateNum)) {
                revert PendingStateNotConsolidable();
            }
        }
        _consolidatePendingState(rollup, pendingStateNum);
    }

    /**
     * @notice Internal function to consolidate any pending state that has already exceed the pendingStateTimeout
     * @param rollup Rollup data storage pointer
     * @param pendingStateNum Pending state to consolidate
     */
    function _consolidatePendingState(
        RollupData storage rollup,
        uint64 pendingStateNum
    ) internal {
        // Check if pendingStateNum is in correct range
        // - not consolidated (implicity checks that is not 0)
        // - exist ( has been added)
        if (
            pendingStateNum <= rollup.lastPendingStateConsolidated ||
            pendingStateNum > rollup.lastPendingState
        ) {
            revert PendingStateInvalid();
        }

        PendingState storage currentPendingState = rollup
            .pendingStateTransitions[pendingStateNum];

        // Update state
        uint64 newLastVerifiedBatch = currentPendingState.lastVerifiedBatch;
        rollup.lastVerifiedBatch = newLastVerifiedBatch;
        rollup.batchNumToStateRoot[newLastVerifiedBatch] = currentPendingState
            .stateRoot;
        rollup.lastLocalExitRoot = currentPendingState.exitRoot;

        // Update pending state
        rollup.lastPendingStateConsolidated = pendingStateNum;

        // Interact with globalExitRootManager
        globalExitRootManager.updateExitRoot(getRollupExitRoot());

        emit ConsolidatePendingState(
            rollupAddressToID[address(rollup.rollupContract)],
            newLastVerifiedBatch,
            currentPendingState.stateRoot,
            currentPendingState.exitRoot,
            pendingStateNum
        );
    }

    /////////////////////////////////
    // Soundness protection functions
    /////////////////////////////////

    /**
     * @notice Allows the trusted aggregator to override the pending state
     * if it's possible to prove a different state root given the same batches
     * @param rollupID Rollup identifier
     * @param initPendingStateNum Init pending state, 0 if consolidated state is used
     * @param finalPendingStateNum Final pending state, that will be used to compare with the newStateRoot
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot  New local exit root once the batch is processed
     * @param newStateRoot New State root once the batch is processed
     * @param proof Fflonk proof
     */
    function overridePendingState(
        uint32 rollupID,
        uint64 initPendingStateNum,
        uint64 finalPendingStateNum,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 newStateRoot,
        bytes32[24] calldata proof
    ) external onlyRole(_TRUSTED_AGGREGATOR_ROLE) {
        RollupData storage rollup = rollupIDToRollupData[rollupID];

        _proveDistinctPendingState(
            rollup,
            initPendingStateNum,
            finalPendingStateNum,
            initNumBatch,
            finalNewBatch,
            newLocalExitRoot,
            newStateRoot,
            proof
        );

        // Consolidate state
        rollup.lastVerifiedBatch = finalNewBatch;
        rollup.batchNumToStateRoot[finalNewBatch] = newStateRoot;
        rollup.lastLocalExitRoot = newLocalExitRoot;

        // Clean pending state if any
        if (rollup.lastPendingState > 0) {
            rollup.lastPendingState = 0;
            rollup.lastPendingStateConsolidated = 0;
        }

        // Interact with globalExitRootManager
        globalExitRootManager.updateExitRoot(getRollupExitRoot());

        // Update trusted aggregator timeout to max
        trustedAggregatorTimeout = _HALT_AGGREGATION_TIMEOUT;

        emit OverridePendingState(
            rollupID,
            finalNewBatch,
            newStateRoot,
            newLocalExitRoot,
            msg.sender
        );
    }

    /**
     * @notice Allows activate the emergency state if its possible to prove a different state root given the same batches
     * @param rollupID Rollup identifier
     * @param initPendingStateNum Init pending state, 0 if consolidated state is used
     * @param finalPendingStateNum Final pending state, that will be used to compare with the newStateRoot
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot  New local exit root once the batch is processed
     * @param newStateRoot New State root once the batch is processed
     * @param proof Fflonk proof
     */
    function proveNonDeterministicPendingState(
        uint32 rollupID,
        uint64 initPendingStateNum,
        uint64 finalPendingStateNum,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 newStateRoot,
        bytes32[24] calldata proof
    ) external ifNotEmergencyState {
        RollupData storage rollup = rollupIDToRollupData[rollupID];

        _proveDistinctPendingState(
            rollup,
            initPendingStateNum,
            finalPendingStateNum,
            initNumBatch,
            finalNewBatch,
            newLocalExitRoot,
            newStateRoot,
            proof
        );

        emit ProveNonDeterministicPendingState(
            rollup.pendingStateTransitions[finalPendingStateNum].stateRoot,
            newStateRoot
        );

        // Activate emergency state
        _activateEmergencyState();
    }

    /**
     * @notice Internal function that proves a different state root given the same batches to verify
     * @param rollup Rollup Data struct that will be checked
     * @param initPendingStateNum Init pending state, 0 if consolidated state is used
     * @param finalPendingStateNum Final pending state, that will be used to compare with the newStateRoot
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot  New local exit root once the batch is processed
     * @param newStateRoot New State root once the batch is processed
     * @param proof Fflonk proof
     */
    function _proveDistinctPendingState(
        RollupData storage rollup,
        uint64 initPendingStateNum,
        uint64 finalPendingStateNum,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 newStateRoot,
        bytes32[24] calldata proof
    ) internal view virtual {
        bytes32 oldStateRoot;

        if (initNumBatch < rollup.lastVerifiedBatchBeforeUpgrade) {
            revert InitBatchMustMatchCurrentForkID();
        }

        // Use pending state if specified, otherwise use consolidated state
        if (initPendingStateNum != 0) {
            // Check that pending state exist
            // Already consolidated pending states can be used aswell
            if (initPendingStateNum > rollup.lastPendingState) {
                revert PendingStateDoesNotExist();
            }

            // Check choosen pending state
            PendingState storage initPendingState = rollup
                .pendingStateTransitions[initPendingStateNum];

            // Get oldStateRoot from init pending state
            oldStateRoot = initPendingState.stateRoot;

            // Check initNumBatch matches the init pending state
            if (initNumBatch != initPendingState.lastVerifiedBatch) {
                revert InitNumBatchDoesNotMatchPendingState();
            }
        } else {
            // Use consolidated state
            oldStateRoot = rollup.batchNumToStateRoot[initNumBatch];
            if (oldStateRoot == bytes32(0)) {
                revert OldStateRootDoesNotExist();
            }

            // Check initNumBatch is inside the range, sanity check
            if (initNumBatch > rollup.lastVerifiedBatch) {
                revert InitNumBatchAboveLastVerifiedBatch();
            }
        }

        // Assert final pending state num is in correct range
        // - exist ( has been added)
        // - bigger than the initPendingstate
        // - not consolidated
        if (
            finalPendingStateNum > rollup.lastPendingState ||
            finalPendingStateNum <= initPendingStateNum ||
            finalPendingStateNum <= rollup.lastPendingStateConsolidated
        ) {
            revert FinalPendingStateNumInvalid();
        }

        // Check final num batch
        if (
            finalNewBatch !=
            rollup
                .pendingStateTransitions[finalPendingStateNum]
                .lastVerifiedBatch
        ) {
            revert FinalNumBatchDoesNotMatchPendingState();
        }

        // Get snark bytes
        bytes memory snarkHashBytes = _getInputSnarkBytes(
            rollup,
            initNumBatch,
            finalNewBatch,
            newLocalExitRoot,
            oldStateRoot,
            newStateRoot
        );

        // Calulate the snark input
        uint256 inputSnark = uint256(sha256(snarkHashBytes)) % _RFIELD;

        // TODO(radomski): Lower does not work
        // Verify proof
        // if (!rollup.verifier.verifyProof(proof, [inputSnark])) {
        //     revert InvalidProof();
        // }

        if (
            rollup.pendingStateTransitions[finalPendingStateNum].stateRoot ==
            newStateRoot
        ) {
            revert StoredRootMustBeDifferentThanNewRoot();
        }
    }

    /**
     * @notice Function to update the batch fee based on the new verified batches
     * The batch fee will not be updated when the trusted aggregator verifies batches
     * @param newLastVerifiedBatch New last verified batch
     */
    function _updateBatchFee(
        RollupData storage rollup,
        uint64 newLastVerifiedBatch
    ) internal {
        uint64 currentLastVerifiedBatch = _getLastVerifiedBatch(rollup);
        uint64 currentBatch = newLastVerifiedBatch;

        uint256 totalBatchesAboveTarget;
        uint256 newBatchesVerified = newLastVerifiedBatch -
            currentLastVerifiedBatch;

        uint256 targetTimestamp = block.timestamp - verifyBatchTimeTarget;

        while (currentBatch != currentLastVerifiedBatch) {
            // Load sequenced batchdata
            SequencedBatchData storage currentSequencedBatchData = rollup
                .sequencedBatches[currentBatch];

            // Check if timestamp is below the verifyBatchTimeTarget
            if (
                targetTimestamp < currentSequencedBatchData.sequencedTimestamp
            ) {
                // update currentBatch
                currentBatch = currentSequencedBatchData
                    .previousLastBatchSequenced;
            } else {
                // The rest of batches will be above
                totalBatchesAboveTarget =
                    currentBatch -
                    currentLastVerifiedBatch;
                break;
            }
        }

        uint256 totalBatchesBelowTarget = newBatchesVerified -
            totalBatchesAboveTarget;

        // _MAX_BATCH_FEE --> (< 70 bits)
        // multiplierBatchFee --> (< 10 bits)
        // _MAX_BATCH_MULTIPLIER = 12
        // multiplierBatchFee ** _MAX_BATCH_MULTIPLIER --> (< 128 bits)
        // batchFee * (multiplierBatchFee ** _MAX_BATCH_MULTIPLIER)-->
        // (< 70 bits) * (< 128 bits) = < 256 bits

        // TODO(radomski: Lower has weird precedense errors
        // Since all the following operations cannot overflow, we can optimize this operations with unchecked
        unchecked {
            if (totalBatchesBelowTarget < totalBatchesAboveTarget) {
                // There are more batches above target, fee is multiplied
                uint256 diffBatches = totalBatchesAboveTarget -
                    totalBatchesBelowTarget;

                //diffBatches = diffBatches > _MAX_BATCH_MULTIPLIER
                //    ? _MAX_BATCH_MULTIPLIER
                //    : diffBatches;

                // For every multiplierBatchFee multiplication we must shift 3 zeroes since we have 3 decimals
                _batchFee =
                    (_batchFee * (uint256(multiplierBatchFee) ** diffBatches)) /
                    (uint256(1000) ** diffBatches);
            } else {
                // There are more batches below target, fee is divided
                uint256 diffBatches = totalBatchesBelowTarget -
                    totalBatchesAboveTarget;

                //diffBatches = diffBatches > _MAX_BATCH_MULTIPLIER
                //    ? _MAX_BATCH_MULTIPLIER
                //    : diffBatches;

                // For every multiplierBatchFee multiplication we must shift 3 zeroes since we have 3 decimals
                uint256 accDivisor = (uint256(1 ether) *
                    (uint256(multiplierBatchFee) ** diffBatches)) /
                    (uint256(1000) ** diffBatches);

                // multiplyFactor = multiplierBatchFee ** diffBatches / 10 ** (diffBatches * 3)
                // accDivisor = 1E18 * multiplyFactor
                // 1E18 * batchFee / accDivisor = batchFee / multiplyFactor
                // < 60 bits * < 70 bits / ~60 bits --> overflow not possible
                _batchFee = (uint256(1 ether) * _batchFee) / accDivisor;
            }
        }

        // Batch fee must remain inside a range
        if (_batchFee > _MAX_BATCH_FEE) {
            _batchFee = _MAX_BATCH_FEE;
        } else if (_batchFee < _MIN_BATCH_FEE) {
            _batchFee = _MIN_BATCH_FEE;
        }
    }

    ////////////////////////
    // Emergency state functions
    ////////////////////////

    /**
     * @notice Function to activate emergency state, which also enables the emergency mode on both PolygonRollupManager and PolygonZkEVMBridge contracts
     * If not called by the owner must not have been aggregated in a _HALT_AGGREGATION_TIMEOUT period and an emergency state was not happened in the same period
     */
    function activateEmergencyState() external {
        if (!hasRole(_EMERGENCY_COUNCIL_ROLE, msg.sender)) {
            if (
                lastAggregationTimestamp == 0 ||
                lastAggregationTimestamp + _HALT_AGGREGATION_TIMEOUT >
                block.timestamp ||
                lastDeactivatedEmergencyStateTimestamp +
                    _HALT_AGGREGATION_TIMEOUT >
                block.timestamp
            ) {
                revert HaltTimeoutNotExpired();
            }
        }
        _activateEmergencyState();
    }

    /**
     * @notice Function to deactivate emergency state on both PolygonRollupManager and PolygonZkEVMBridge contracts
     */
    function deactivateEmergencyState()
        external
        onlyRole(_STOP_EMERGENCY_ROLE)
    {
        // Set last deactivated emergency state
        lastDeactivatedEmergencyStateTimestamp = uint64(block.timestamp);

        // Deactivate emergency state on PolygonZkEVMBridge
        bridgeAddress.deactivateEmergencyState();

        // Deactivate emergency state on this contract
        super._deactivateEmergencyState();
    }

    /**
     * @notice Internal function to activate emergency state on both PolygonRollupManager and PolygonZkEVMBridge contracts
     */
    function _activateEmergencyState() internal override {
        // Activate emergency state on PolygonZkEVM Bridge
        bridgeAddress.activateEmergencyState();

        // Activate emergency state on this contract
        super._activateEmergencyState();
    }

    //////////////////
    // Setter functions
    //////////////////

    /**
     * @notice Set a new pending state timeout
     * The timeout can only be lowered, except if emergency state is active
     * @param newTrustedAggregatorTimeout Trusted aggregator timeout
     */
    function setTrustedAggregatorTimeout(
        uint64 newTrustedAggregatorTimeout
    ) external onlyRole(_TWEAK_PARAMETERS_ROLE) {
        if (!isEmergencyState) {
            if (newTrustedAggregatorTimeout >= trustedAggregatorTimeout) {
                revert NewTrustedAggregatorTimeoutMustBeLower();
            }
        }

        trustedAggregatorTimeout = newTrustedAggregatorTimeout;
        emit SetTrustedAggregatorTimeout(newTrustedAggregatorTimeout);
    }

    /**
     * @notice Set a new trusted aggregator timeout
     * The timeout can only be lowered, except if emergency state is active
     * @param newPendingStateTimeout Trusted aggregator timeout
     */
    function setPendingStateTimeout(
        uint64 newPendingStateTimeout
    ) external onlyRole(_TWEAK_PARAMETERS_ROLE) {
        if (!isEmergencyState) {
            if (newPendingStateTimeout >= pendingStateTimeout) {
                revert NewPendingStateTimeoutMustBeLower();
            }
        }

        pendingStateTimeout = newPendingStateTimeout;
        emit SetPendingStateTimeout(newPendingStateTimeout);
    }

    /**
     * @notice Set a new multiplier batch fee
     * @param newMultiplierBatchFee multiplier batch fee
     */
    function setMultiplierBatchFee(
        uint16 newMultiplierBatchFee
    ) external onlyRole(_TWEAK_PARAMETERS_ROLE) {
        if (newMultiplierBatchFee < 1000 || newMultiplierBatchFee > 1023) {
            revert InvalidRangeMultiplierBatchFee();
        }

        multiplierBatchFee = newMultiplierBatchFee;
        emit SetMultiplierBatchFee(newMultiplierBatchFee);
    }

    /**
     * @notice Set a new verify batch time target
     * This value will only be relevant once the aggregation is decentralized, so
     * the trustedAggregatorTimeout should be zero or very close to zero
     * @param newVerifyBatchTimeTarget Verify batch time target
     */
    function setVerifyBatchTimeTarget(
        uint64 newVerifyBatchTimeTarget
    ) external onlyRole(_TWEAK_PARAMETERS_ROLE) {
        if (newVerifyBatchTimeTarget > 1 days) {
            revert InvalidRangeBatchTimeTarget();
        }
        verifyBatchTimeTarget = newVerifyBatchTimeTarget;
        emit SetVerifyBatchTimeTarget(newVerifyBatchTimeTarget);
    }

    /**
     * @notice Set the current batch fee
     * @param newBatchFee new batch fee
     */
    function setBatchFee(uint256 newBatchFee) external onlyRole(_SET_FEE_ROLE) {
        // check fees min and max
        if (newBatchFee > _MAX_BATCH_FEE || newBatchFee < _MIN_BATCH_FEE) {
            revert BatchFeeOutOfRange();
        }
        _batchFee = newBatchFee;
        emit SetBatchFee(newBatchFee);
    }

    ////////////////////////
    // view/pure functions
    ///////////////////////

    /**
     * @notice Get the current rollup exit root
     * Compute using all the local exit roots of all rollups the rollup exit root
     * Since it's expected to have no more than 10 rollups in this first version, even if this approach
     * has a gas consumption that scales linearly with the rollups added, it's ok
     * In a future versions this computation will be done inside the circuit
     */
    function getRollupExitRoot() public view returns (bytes32) {
        uint256 currentNodes = rollupCount;

        // If there are no nodes return 0
        if (currentNodes == 0) {
            return bytes32(0);
        }

        // This array will contain the nodes of the current iteration
        bytes32[] memory tmpTree = new bytes32[](currentNodes);

        // In the first iteration the nodes will be the leafs which are the local exit roots of each network
        for (uint256 i = 0; i < currentNodes; i++) {
            // The first rollup ID starts on 1
            tmpTree[i] = rollupIDToRollupData[uint32(i + 1)].lastLocalExitRoot;
        }

        // This variable will keep track of the zero hashes
        bytes32 currentZeroHashHeight = 0;

        // This variable will keep track of the reamining levels to compute
        uint256 remainingLevels = _EXIT_TREE_DEPTH;

        // Calculate the root of the sub-tree that contains all the localExitRoots
        while (currentNodes != 1) {
            uint256 nextIterationNodes = currentNodes / 2 + (currentNodes % 2);
            bytes32[] memory nextTmpTree = new bytes32[](nextIterationNodes);
            for (uint256 i = 0; i < nextIterationNodes; i++) {
                // if we are on the last iteration of the current level and the nodes are odd
                if (i == nextIterationNodes - 1 && (currentNodes % 2) == 1) {
                    nextTmpTree[i] = keccak256(
                        abi.encodePacked(tmpTree[i * 2], currentZeroHashHeight)
                    );
                } else {
                    nextTmpTree[i] = keccak256(
                        abi.encodePacked(tmpTree[i * 2], tmpTree[(i * 2) + 1])
                    );
                }
            }

            // Update tree variables
            tmpTree = nextTmpTree;
            currentNodes = nextIterationNodes;
            currentZeroHashHeight = keccak256(
                abi.encodePacked(currentZeroHashHeight, currentZeroHashHeight)
            );
            remainingLevels--;
        }

        bytes32 currentRoot = tmpTree[0];

        // Calculate remaining levels, since it's a sequencial merkle tree, the rest of the tree are zeroes
        for (uint256 i = 0; i < remainingLevels; i++) {
            currentRoot = keccak256(
                abi.encodePacked(currentRoot, currentZeroHashHeight)
            );
            currentZeroHashHeight = keccak256(
                abi.encodePacked(currentZeroHashHeight, currentZeroHashHeight)
            );
        }
        return currentRoot;
    }

    /**
     * @notice Get the last verified batch
     */
    function getLastVerifiedBatch(
        uint32 rollupID
    ) public view returns (uint64) {
        return _getLastVerifiedBatch(rollupIDToRollupData[rollupID]);
    }

    /**
     * @notice Get the last verified batch
     */
    function _getLastVerifiedBatch(
        RollupData storage rollup
    ) internal view returns (uint64) {
        if (rollup.lastPendingState > 0) {
            return
                rollup
                    .pendingStateTransitions[rollup.lastPendingState]
                    .lastVerifiedBatch;
        } else {
            return rollup.lastVerifiedBatch;
        }
    }

    /**
     * @notice Returns a boolean that indicates if the pendingStateNum is or not consolidable
     * @param rollupID Rollup id
     * @param pendingStateNum Pending state number to check
     * Note that his function does not check if the pending state currently exists, or if it's consolidated already
     */
    function isPendingStateConsolidable(
        uint32 rollupID,
        uint64 pendingStateNum
    ) public view returns (bool) {
        return
            _isPendingStateConsolidable(
                rollupIDToRollupData[rollupID],
                pendingStateNum
            );
    }

    /**
     * @notice Returns a boolean that indicates if the pendingStateNum is or not consolidable
     * @param rollup Rollup data storage pointer
     * @param pendingStateNum Pending state number to check
     * Note that his function does not check if the pending state currently exists, or if it's consolidated already
     */
    function _isPendingStateConsolidable(
        RollupData storage rollup,
        uint64 pendingStateNum
    ) internal view returns (bool) {
        return (rollup.pendingStateTransitions[pendingStateNum].timestamp +
            pendingStateTimeout <=
            block.timestamp);
    }

    /**
     * @notice Function to calculate the reward to verify a single batch
     */
    function calculateRewardPerBatch() public view returns (uint256) {
        uint256 currentBalance = pol.balanceOf(address(this));

        // Total Batches to be verified = total Sequenced Batches - total verified Batches
        uint256 totalBatchesToVerify = totalSequencedBatches -
            totalVerifiedBatches;

        if (totalBatchesToVerify == 0) return 0;
        return currentBalance / totalBatchesToVerify;
    }

    /**
     * @notice Get batch fee
     * This function is used instad of the automatic public view one,
     * because in a future might change the behaviour and we will be able to mantain the interface
     */
    function getBatchFee() public view returns (uint256) {
        return _batchFee;
    }

    /**
     * @notice Get forced batch fee
     */
    function getForcedBatchFee() public view returns (uint256) {
        return _batchFee * 100;
    }

    /**
     * @notice Function to calculate the input snark bytes
     * @param rollupID Rollup id used to calculate the input snark bytes
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot New local exit root once the batch is processed
     * @param oldStateRoot State root before batch is processed
     * @param newStateRoot New State root once the batch is processed
     */
    function getInputSnarkBytes(
        uint32 rollupID,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 oldStateRoot,
        bytes32 newStateRoot
    ) public view returns (bytes memory) {
        return
            _getInputSnarkBytes(
                rollupIDToRollupData[rollupID],
                initNumBatch,
                finalNewBatch,
                newLocalExitRoot,
                oldStateRoot,
                newStateRoot
            );
    }

    /**
     * @notice Function to calculate the input snark bytes
     * @param rollup Rollup data storage pointer
     * @param initNumBatch Batch which the aggregator starts the verification
     * @param finalNewBatch Last batch aggregator intends to verify
     * @param newLocalExitRoot New local exit root once the batch is processed
     * @param oldStateRoot State root before batch is processed
     * @param newStateRoot New State root once the batch is processed
     */
    function _getInputSnarkBytes(
        RollupData storage rollup,
        uint64 initNumBatch,
        uint64 finalNewBatch,
        bytes32 newLocalExitRoot,
        bytes32 oldStateRoot,
        bytes32 newStateRoot
    ) internal view returns (bytes memory) {
        // Sanity check
        bytes32 oldAccInputHash = rollup
            .sequencedBatches[initNumBatch]
            .accInputHash;

        bytes32 newAccInputHash = rollup
            .sequencedBatches[finalNewBatch]
            .accInputHash;

        // Sanity check
        if (initNumBatch != 0 && oldAccInputHash == bytes32(0)) {
            revert OldAccInputHashDoesNotExist();
        }

        if (newAccInputHash == bytes32(0)) {
            revert NewAccInputHashDoesNotExist();
        }

        // Check that new state root is inside goldilocks field
        if (!_checkStateRootInsidePrime(uint256(newStateRoot))) {
            revert NewStateRootNotInsidePrime();
        }

        return
            abi.encodePacked(
                msg.sender,
                oldStateRoot,
                oldAccInputHash,
                initNumBatch,
                rollup.chainID,
                rollup.forkID,
                newStateRoot,
                newAccInputHash,
                newLocalExitRoot,
                finalNewBatch
            );
    }

    /**
     * @notice Function to check if the state root is inside of the prime field
     * @param newStateRoot New State root once the batch is processed
     */
    function _checkStateRootInsidePrime(
        uint256 newStateRoot
    ) internal pure returns (bool) {
        if (
            ((newStateRoot & _MAX_UINT_64) < _GOLDILOCKS_PRIME_FIELD) &&
            (((newStateRoot >> 64) & _MAX_UINT_64) < _GOLDILOCKS_PRIME_FIELD) &&
            (((newStateRoot >> 128) & _MAX_UINT_64) <
                _GOLDILOCKS_PRIME_FIELD) &&
            ((newStateRoot >> 192) < _GOLDILOCKS_PRIME_FIELD)
        ) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * @notice Get rollup state root given a batch number
     * @param rollupID Rollup identifier
     * @param batchNum Batch number
     */
    function getRollupBatchNumToStateRoot(
        uint32 rollupID,
        uint64 batchNum
    ) public view returns (bytes32) {
        return rollupIDToRollupData[rollupID].batchNumToStateRoot[batchNum];
    }

    /**
     * @notice Get rollup sequence batches struct given a batch number
     * @param rollupID Rollup identifier
     * @param batchNum Batch number
     */
    function getRollupSequencedBatches(
        uint32 rollupID,
        uint64 batchNum
    ) public view returns (SequencedBatchData memory) {
        return rollupIDToRollupData[rollupID].sequencedBatches[batchNum];
    }

    /**
     * @notice Get rollup sequence pending state struct given a batch number
     * @param rollupID Rollup identifier
     * @param batchNum Batch number
     */
    function getRollupPendingStateTransitions(
        uint32 rollupID,
        uint64 batchNum
    ) public view returns (PendingState memory) {
        return rollupIDToRollupData[rollupID].pendingStateTransitions[batchNum];
    }
}
// 
// // This is some weird backtick, it takes two bytes, i need to understand what is going on
// // Don’t allow fillDeadline to be more than several bundles into the future.
// //’

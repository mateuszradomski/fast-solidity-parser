#include "./src/engine/utils.c"
#include "./src/engine/tokenize.c"
#include "./src/engine/yulLexer.c"
#include "./src/engine/parser.c"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include <glob.h>
#include <math.h>

char *skippedTests[] = {
    "tests/solcTests/105_constant_input_parameter.sol",
    "tests/solcTests/226_inheriting_library.sol",
    "tests/solcTests/428_bare_revert.sol",
    "tests/solcTests/abi_decode_calldata.sol",
    "tests/solcTests/abi_decode_memory.sol",
    "tests/solcTests/abi_decode_storage.sol",
    "tests/solcTests/abi_encodeCall_tuple_from_error_event.sol",
    "tests/solcTests/abstract_only.sol",
    "tests/solcTests/abstract_without_contract.sol",
    "tests/solcTests/address_constant_payable.sol",
    "tests/solcTests/address_invalid_state_mutability.sol",
    "tests/solcTests/address_public_payable_error.sol",
    "tests/solcTests/anonymous.sol",
    "tests/solcTests/anonymous_event_multiple_anonymous_specifiers.sol",
    "tests/solcTests/array_length_cannot_be_constant_function_parameter.sol",
    "tests/solcTests/array_type_range.sol",
    "tests/solcTests/as_function_param.sol",
    "tests/solcTests/at_file_level.sol",
    "tests/solcTests/blank_space_version.sol",
    "tests/solcTests/broken_version_3.sol",
    "tests/solcTests/bytes_concat_wrong_type_empty_array_literal.sol",
    "tests/solcTests/calling_operator_as_attached_function_via_operator_name.sol",
    "tests/solcTests/combining_hex_and_denomination.sol",
    "tests/solcTests/constant_forward_reference_struct.sol",
    "tests/solcTests/constant_is_keyword.sol",
    "tests/solcTests/constant_override.sol",
    "tests/solcTests/constant_unassigned.sol",
    "tests/solcTests/constant_virtual.sol",
    "tests/solcTests/constant_with_visibility.sol",
    "tests/solcTests/constant_with_visibility_inverted.sol",
    "tests/solcTests/constructor_internal_internal.sol",
    "tests/solcTests/constructor_internal_public.sol",
    "tests/solcTests/constructor_override.sol",
    "tests/solcTests/constructor_payable_payable.sol",
    "tests/solcTests/constructor_public_internal.sol",
    "tests/solcTests/constructor_public_public.sol",
    "tests/solcTests/constructor_state_mutability.sol",
    "tests/solcTests/constructor_virtual.sol",
    "tests/solcTests/constructor_without_implementation.sol",
    "tests/solcTests/control_character_returned_in_string.sol",
    "tests/solcTests/detect_double_override.sol",
    "tests/solcTests/double_asterisk.sol",
    "tests/solcTests/double_specifier.sol",
    "tests/solcTests/elementary_non_address_state_mutability_argument.sol",
    "tests/solcTests/elementary_non_address_state_mutability_catch.sol",
    "tests/solcTests/elementary_non_address_state_mutability_error_argument.sol",
    "tests/solcTests/elementary_non_address_state_mutability_event_argument.sol",
    "tests/solcTests/elementary_non_address_state_mutability_file_var.sol",
    "tests/solcTests/elementary_non_address_state_mutability_local.sol",
    "tests/solcTests/elementary_non_address_state_mutability_modifier_argument.sol",
    "tests/solcTests/elementary_non_address_state_mutability_return.sol",
    "tests/solcTests/elementary_non_address_state_mutability_state_variable.sol",
    "tests/solcTests/elementary_non_address_state_mutability_try_returns.sol",
    "tests/solcTests/emit_empty.sol",
    "tests/solcTests/emit_without_event.sol",
    "tests/solcTests/empty_catch.sol",
    "tests/solcTests/empty_returns.sol",
    "tests/solcTests/empty_tuple_event.sol",
    "tests/solcTests/empty_version.sol",
    "tests/solcTests/event_multiple_indexed_of_one_parameter.sol",
    "tests/solcTests/event_with_no_argument_list.sol",
    "tests/solcTests/experimental_pragma_empty.sol",
    "tests/solcTests/external_constructor.sol",
    "tests/solcTests/external_variable.sol",
    "tests/solcTests/file_level_memory.sol",
    "tests/solcTests/file_level_memory_inverted.sol",
    "tests/solcTests/file_level_multiple_constant_keywords.sol",
    "tests/solcTests/file_level_variable_visibility.sol",
    "tests/solcTests/fixed_literal_with_double_radix.sol",
    "tests/solcTests/forward_reference_err.sol",
    "tests/solcTests/free_constructor.sol",
    "tests/solcTests/free_fallback.sol",
    "tests/solcTests/free_receive.sol",
    "tests/solcTests/function_named_constructor.sol",
    "tests/solcTests/function_type_constructor.sol",
    "tests/solcTests/function_type_constructor_local.sol",
    "tests/solcTests/function_type_multiple_visibility.sol",
    "tests/solcTests/global_multiple_global_keywords.sol",
    "tests/solcTests/gwei_as_identifier.sol",
    "tests/solcTests/hex_string_misaligned_underscore.sol",
    "tests/solcTests/immutable_at_file_level.sol",
    "tests/solcTests/implementing_operator_with_attached_free_function.sol",
    "tests/solcTests/import_complex_invalid_from.sol",
    "tests/solcTests/import_complex_without_from.sol",
    "tests/solcTests/import_contract_function_error.sol",
    "tests/solcTests/import_invalid_token.sol",
    "tests/solcTests/inline_array_empty_cells_check_lvalue.sol",
    "tests/solcTests/inline_array_empty_cells_check_without_lvalue.sol",
    "tests/solcTests/interface_constructor.sol",
    "tests/solcTests/invalid_denomination_address.sol",
    "tests/solcTests/invalid_denomination_on_bool.sol",
    "tests/solcTests/invalid_denomination_on_string.sol",
    "tests/solcTests/invalid_error_name.sol",
    "tests/solcTests/invalid_fixed_conversion_leading_zeroes_check.sol",
    "tests/solcTests/invalid_function_named_unicode.sol",
    "tests/solcTests/invalid_function_parameter_and_return_var_mutability.sol",
    "tests/solcTests/invalid_function_parameter_and_return_var_visibility.sol",
    "tests/solcTests/invalid_hex_number.sol",
    "tests/solcTests/invalid_parameter_mutability.sol",
    "tests/solcTests/invalid_parameter_visibility.sol",
    "tests/solcTests/invalid_pragma.sol",
    "tests/solcTests/invalid_returns_vars_and_catch_parameter_indexed.sol",
    "tests/solcTests/invalid_returns_vars_and_catch_parameter_mutability.sol",
    "tests/solcTests/invalid_returns_vars_and_catch_parameter_visibility.sol",
    "tests/solcTests/invalid_state_variable_location.sol",
    "tests/solcTests/invalid_variable_indexed.sol",
    "tests/solcTests/invalid_variable_mutablity.sol",
    "tests/solcTests/invalid_variable_visibility.sol",
    "tests/solcTests/library.sol",
    "tests/solcTests/library_constructor.sol",
    "tests/solcTests/local_const_variable.sol",
    "tests/solcTests/location_specifiers_for_file_level_var.sol",
    "tests/solcTests/location_specifiers_for_fn_returns_multi.sol",
    "tests/solcTests/location_specifiers_for_locals_multi.sol",
    "tests/solcTests/location_specifiers_for_params.sol",
    "tests/solcTests/location_specifiers_for_params_multi.sol",
    "tests/solcTests/location_specifiers_for_state_variables.sol",
    "tests/solcTests/location_specifiers_for_state_variables_multi.sol",
    "tests/solcTests/malformed_enum_declaration.sol",
    "tests/solcTests/mapping_nonelementary_key_1.sol",
    "tests/solcTests/mapping_nonelementary_key_4.sol",
    "tests/solcTests/mapping_with_names_nested_5.sol",
    "tests/solcTests/max_depth_reached_1.sol",
    "tests/solcTests/max_depth_reached_2.sol",
    "tests/solcTests/max_depth_reached_3.sol",
    "tests/solcTests/missing_argument_in_named_args.sol",
    "tests/solcTests/missing_parameter_name_in_named_args.sol",
    "tests/solcTests/missing_variable_name_in_declaration.sol",
    "tests/solcTests/modifier_without_semicolon.sol",
    "tests/solcTests/multiline_unicode_direction_override_7.sol",
    "tests/solcTests/multiple_event_arg_trailing_comma.sol",
    "tests/solcTests/multiple_function_param_trailing_comma.sol",
    "tests/solcTests/multiple_modifier_arg_trailing_comma.sol",
    "tests/solcTests/multiple_modifier_overrides.sol",
    "tests/solcTests/multiple_mutability_specifiers.sol",
    "tests/solcTests/multiple_parameter_location.sol",
    "tests/solcTests/multiple_return_param_trailing_comma.sol",
    "tests/solcTests/multiple_returns_vars_and_catch_parameter_location.sol",
    "tests/solcTests/multiple_state_mutability_specifiers.sol",
    "tests/solcTests/multiple_visibility_specifiers.sol",
    "tests/solcTests/multiple_visibility_specifiers_external.sol",
    "tests/solcTests/named_arguments_empty.sol",
    "tests/solcTests/non_constant.sol",
    "tests/solcTests/non_value_type_contract_err.sol",
    "tests/solcTests/non_value_type_enum_err.sol",
    "tests/solcTests/non_value_type_function_err.sol",
    "tests/solcTests/non_value_type_mapping_err.sol",
    "tests/solcTests/non_value_type_struct_err.sol",
    "tests/solcTests/one_dot.sol",
    "tests/solcTests/operator_parsing_function_name_missing.sol",
    "tests/solcTests/operator_parsing_no_brace.sol",
    "tests/solcTests/operator_parsing_non_user_definable.sol",
    "tests/solcTests/operator_parsing_not_an_operator.sol",
    "tests/solcTests/operator_parsing_operator_name_empty_string.sol",
    "tests/solcTests/operator_parsing_operator_name_missing.sol",
    "tests/solcTests/operator_parsing_operator_named_as.sol",
    "tests/solcTests/override_empty_list.sol",
    "tests/solcTests/override_multiple_fail1.sol",
    "tests/solcTests/override_multiple_fail2.sol",
    "tests/solcTests/override_multiple_fail3.sol",
    "tests/solcTests/override_multiple_fail4.sol",
    "tests/solcTests/parsing_stdlib_import_1.sol",
    "tests/solcTests/parsing_stdlib_import_2.sol",
    "tests/solcTests/parsing_stdlib_import_3.sol",
    "tests/solcTests/parsing_stdlib_import_4.sol",
    "tests/solcTests/parsing_stdlib_import_without_pragma_1.sol",
    "tests/solcTests/parsing_stdlib_import_without_pragma_2.sol",
    "tests/solcTests/pragma_illegal.sol",
    "tests/solcTests/recursive_err.sol",
    "tests/solcTests/recursive_function_paramter_err.sol",
    "tests/solcTests/returns_in_constructor.sol",
    "tests/solcTests/revert_revert.sol",
    "tests/solcTests/self_reference_err.sol",
    "tests/solcTests/single_event_arg_trailing_comma.sol",
    "tests/solcTests/single_function_param_trailing_comma.sol",
    "tests/solcTests/single_modifier_arg_trailing_comma.sol",
    "tests/solcTests/single_return_param_trailing_comma.sol",
    "tests/solcTests/string_concat_wrong_type_empty_array_literal.sol",
    "tests/solcTests/string_multipart_hex_valid_parts.sol",
    "tests/solcTests/string_multipart_newline_without_hex_prefix.sol",
    "tests/solcTests/string_multipart_only_hex.sol",
    "tests/solcTests/string_multipart_only_regular.sol",
    "tests/solcTests/string_multipart_unicode_mixed.sol",
    "tests/solcTests/string_terminated_by_backslash.sol",
    "tests/solcTests/string_unterminated.sol",
    "tests/solcTests/string_unterminated_no_new_line.sol",
    "tests/solcTests/struct_constant.sol",
    "tests/solcTests/trailing_comma_in_named_args.sol",
    "tests/solcTests/trailing_dot3.sol",
    "tests/solcTests/tuples_decl_without_rhs.sol",
    "tests/solcTests/tuples_without_commas.sol",
    "tests/solcTests/two_denominations_same_literal.sol",
    "tests/solcTests/typeNotRegularIdentifierContractName.sol",
    "tests/solcTests/typeNotRegularIdentifierFunction.sol",
    "tests/solcTests/typeNotRegularIdentifierParameter.sol",
    "tests/solcTests/typeNotRegularIdentifierStateVariable.sol",
    "tests/solcTests/typeNotRegularIdentifierVariable.sol",
    "tests/solcTests/unchecked_for_header.sol",
    "tests/solcTests/unchecked_post_for.sol",
    "tests/solcTests/unchecked_vardecl.sol",
    "tests/solcTests/unexpected.sol",
    "tests/solcTests/unicode_comment_direction_override.sol",
    "tests/solcTests/unicode_direction_in_source_1.sol",
    "tests/solcTests/unicode_direction_in_source_2.sol",
    "tests/solcTests/unimplemented_library.sol",
    "tests/solcTests/unknown_pragma.sol",
    "tests/solcTests/unterminated_pragma.sol",
    "tests/solcTests/user_defined_value_type_err.sol",
    "tests/solcTests/user_defined_value_type_in_function_err.sol",
    "tests/solcTests/using_empty_list_err.sol",
    "tests/solcTests/using_empty_list_file_level.sol",
    "tests/solcTests/using_lhs_asterisk.sol",
    "tests/solcTests/using_lhs_asterisk_contract.sol",
    "tests/solcTests/var_empty_decl_3.sol",
    "tests/solcTests/wrong_compiler_2.sol",
    "tests/solcTests/wrong_compiler_3.sol",
    "tests/solcTests/wrong_panic.sol",
    "tests/solcTests/zero_dot.sol",
    "tests/solcTests/zero_signature.sol",
};

String entryPointBinaryInterface(Arena *arena, const char *string, int len) {
    String input = { .data = (u8 *)string, .size = len };

    TokenizeResult tokens = tokenize(input, arena);
    Parser parser = createParser(tokens, arena);
    ASTNode node = parseSourceUnit(&parser);

    Serializer s = createSerializer(arena, string, tokens);
    return serialize(&s, &node, input.size);
}

u32 CRC32KoopmanHD8(const u8 *bytes, u32 count) {
    u32 g = 0xf8c9140a;
    u32 crc = 0;

    for(u32 i = 0; i < count; i++) {
        crc ^= (((u32)bytes[0]) << 24);
        for(int i = 0; i < 8; i++) {
            u32 mask = -((crc & 0x80000000) >> 31);
            crc = (crc << 1) ^ (g & mask);
        }
        bytes++;
    }
    
    return crc;
}

static int
isSkipped(const char *filepath, char **skipped, u32 count) {
    for(u32 i = 0; i < count; i++) {
        if(strcmp(filepath, skipped[i]) == 0) {
            return true;
        }
    }

    return false;
}

static void
printHistogram(int *histogram, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += histogram[i];
    }

    int cumulative = 0;
    for (int i = 0; i < count; i++) {
        if (histogram[i] > 0) {
            cumulative += histogram[i];
            double percentage = (double)cumulative / total * 100;
            printf("%d: %d (%.2f%% cumulative)\n", i, histogram[i], percentage);
        }
    }
}

int main() {
    glob_t files = { 0 };

    assert(glob("tests/**/*.sol", 0, 0x0, &files) == 0);
    printf("paths matched = %zu\n", files.gl_pathc);

    Arena arena = arenaCreate(128 * Megabyte, 32 * Kilobyte, 64);

    int totalMemoryUsedHistogram[128] = { 0 };
    int outputBytesPerInputHistogram[128] = { 0 };

    u32 crc = 0;

    for(u32 i = 0; i < files.gl_pathc; i++) {
        char *filepath = files.gl_pathv[i];
        if(isSkipped(filepath, skippedTests, ARRAY_LENGTH(skippedTests))) {
            continue;
        }

        struct stat fileStat;
        int success = stat(filepath, &fileStat);
        assert(success == 0);

        u32 contentLength = fileStat.st_size;
        char *content = arrayPush(&arena, char, contentLength + 1);
        int fd = open(filepath, O_RDWR);
        read(fd, content, contentLength);
        close(fd);
        content[contentLength] = 0;

        size_t memoryUsed = arenaFreeBytes(&arena);
        String result = entryPointBinaryInterface(&arena, content, contentLength);
        memoryUsed -= arenaFreeBytes(&arena);

        int perInputByte = ceil((double)memoryUsed / (double)contentLength);
        totalMemoryUsedHistogram[perInputByte] += 1;

        int outputPerInput = ceil((double)result.size / (double)contentLength);
        outputBytesPerInputHistogram[outputPerInput] += 1;

        crc ^= CRC32KoopmanHD8(result.data, result.size);
        printf("Final CRC = 0x%08x\n", crc);

        printf("%120s %d, %d\n", filepath, i, perInputByte);
    }

    printHistogram(outputBytesPerInputHistogram, ARRAY_LENGTH(outputBytesPerInputHistogram));
    printf("Final CRC = 0x%08x\n", crc);
}

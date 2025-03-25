#[no_mangle]
pub extern fn concat_strings(first_str: *const u8, first_len: usize, second_str: *const u8, second_len: usize) -> *mut u8 {
    let first_slice = unsafe { std::slice::from_raw_parts(first_str, first_len) };
    let second_slice = unsafe { std::slice::from_raw_parts(second_str, second_len) };

    let mut result = Vec::with_capacity(first_len + second_len);
    result.extend_from_slice(first_slice);
    result.extend_from_slice(second_slice);

    let result_ptr = result.as_mut_ptr();
    std::mem::forget(result);
    result_ptr
}

#[no_mangle]
pub extern fn get_string_length(input_str: *const u8, str_len: usize) -> usize {
    let slice = unsafe { std::slice::from_raw_parts(input_str, str_len) };
    slice.len()
}

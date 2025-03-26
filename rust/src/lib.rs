extern crate sha2;
extern crate hex;

use sha2::{Sha256, Digest};

#[no_mangle]
pub extern fn calc_sha256(input_str: *const u8, input_len: usize) -> *mut u8 {
    if input_str.is_null() {
        return std::ptr::null_mut();
    }
    let string_slice = unsafe { std::slice::from_raw_parts(input_str, input_len) };

    let mut hasher = Sha256::new();
    hasher.update(string_slice);
    let result = hasher.finalize();

    let hex_string = hex::encode(result);
    let mut hex_bytes = hex_string.as_bytes().to_vec();
    let result_ptr = hex_bytes.as_mut_ptr();

    std::mem::forget(hex_bytes);
    result_ptr
}
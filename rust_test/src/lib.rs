//extern crate rand;

#[no_mangle]
pub extern "C" fn add_to( x : i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn rust_test_random() -> i32 {
    //rand::random::<i32>()
    0
}


#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}

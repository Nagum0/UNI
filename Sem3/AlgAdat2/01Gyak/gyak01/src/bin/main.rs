fn main() {
    println!(
        "{:?}",
        gyak01::lzw_compression(&String::from("ABABABAACAACCBBAAAAAAAAA"))
    );
}

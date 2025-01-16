use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let A = input.trim().parse::<usize>().unwrap();
	
	writeln!(writer, "{}", A / 5).unwrap();
}
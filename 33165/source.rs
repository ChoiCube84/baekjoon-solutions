use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let T = input.trim().parse::<usize>().unwrap();
	
	let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let V = input.trim().parse::<usize>().unwrap();
	
	writeln!(writer, "{}", T * V).unwrap();
}
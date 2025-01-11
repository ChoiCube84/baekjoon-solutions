use std::cmp::min;
use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let A = input.next().unwrap();
    let B = input.next().unwrap();
	
	let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let C = input.next().unwrap();
    let D = input.next().unwrap();
	
	writeln!(writer, "{}", min(A + D, B + C)).unwrap();
}
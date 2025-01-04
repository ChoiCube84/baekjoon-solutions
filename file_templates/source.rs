use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	// Single input
    // let a = input.trim().parse::<usize>().unwrap();
	
	// Multiple input
	
	// let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    // let a = input.next().unwrap();
    // let b = input.next().unwrap();
    // let c = input.next().unwrap();

	// Print
	
    // writeln!(writer, "Example: a is {}, b is {}, c is {}.", a, b, c).unwrap();
}
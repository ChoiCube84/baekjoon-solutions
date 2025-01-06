use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
	
	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let N = input.next().unwrap();
    let M = input.next().unwrap();
    
	writeln!(writer, "{}", N * M / 2).unwrap();
}
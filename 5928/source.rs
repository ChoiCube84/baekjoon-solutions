use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

    let mut D = input.next().unwrap();
    let mut H = input.next().unwrap();
    let mut M = input.next().unwrap();
	
	D -= 11;
	H -= 11;
	M -= 11;
	
	H += D * 24;
	M += H * 60;
	
	if M < 0 {
		writeln!(writer, "-1").unwrap();
	}
	else {
		writeln!(writer, "{}", M).unwrap();
	}
}
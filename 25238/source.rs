use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let a = input.next().unwrap();
    let b = input.next().unwrap();

	let result = a as f64 * (100 - b) as f64 / 100.0;
	
	if result < 100.0 {
	    writeln!(writer, "1").unwrap();
	}
	else {
	    writeln!(writer, "0").unwrap();
	}
}
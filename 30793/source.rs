use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let px = input.next().unwrap();
    let rx = input.next().unwrap();

	let vx = px as f64 / rx as f64;
	
	if vx < 0.2 {
		writeln!(writer, "weak").unwrap();
	}
	else if vx < 0.4 {
		writeln!(writer, "normal").unwrap();
	}
	else if vx < 0.6 {
		writeln!(writer, "strong").unwrap();
	}
	else {
		writeln!(writer, "very strong").unwrap();
	}
}
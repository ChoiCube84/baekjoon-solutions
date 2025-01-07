use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut a = input.next().unwrap();
    let mut b = input.next().unwrap();
    let mut c = input.next().unwrap();
	
	if a > b {
		(a, b) = (b, a);
	} 
	
	if b > c {
		(b, c) = (c, b);
	}
	
	if a == b && b == c {
		writeln!(writer, "2").unwrap();
	}
	else if a * a + b * b == c * c {
		writeln!(writer, "1").unwrap();
	}
	else {
		writeln!(writer, "0").unwrap();
	}
}
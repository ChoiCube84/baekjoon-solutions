use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let n = input.trim().parse::<usize>().unwrap();
	
	for _ in 0..n {
		let mut input = String::new();
    	stdin().read_line(&mut input).unwrap();
		
		let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

		let a = input.next().unwrap();
		let b = input.next().unwrap();
		let c = input.next().unwrap();
		
		let mut count = 0;
		
		if a >= 10 {
			count += 1;
		}
		if b >= 10 {
			count += 1;
		}
		if c >= 10 {
			count += 1;
		}
		
		writeln!(writer, "{} {} {}", a, b, c).unwrap();
		
		if (count == 0) {
			writeln!(writer, "zilch").unwrap();
			writeln!(writer, "").unwrap();
		}
		else if (count == 1) {
			writeln!(writer, "double").unwrap();
			writeln!(writer, "").unwrap();
		}
		else if (count == 2) {
			writeln!(writer, "double-double").unwrap();
			writeln!(writer, "").unwrap();
		}
		else {
			writeln!(writer, "triple-double").unwrap();
			writeln!(writer, "").unwrap();
		}
	}
}
use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
	
	input.pop();
	
	let mut count = 0;
	
	while input.len() > 1 {
		let mut sum = 0;
		for c in input.chars() {
			sum += c as usize - 0x30;
		}
		input = sum.to_string();
		count += 1;
	}
	
	writeln!(writer, "{}", count).unwrap();
	
	if input.parse::<usize>().unwrap() % 3 == 0 {
		writeln!(writer, "YES").unwrap();
	}
	else {
		writeln!(writer, "NO").unwrap();
	}
}
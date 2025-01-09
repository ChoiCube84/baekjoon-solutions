use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let T = input.trim().parse::<usize>().unwrap();
	
	for _ in 0..T {
		let mut input = String::new();
    	stdin().read_line(&mut input).unwrap();
		
		let mut count = 0;
		
		for c in input.chars() {
			if c == 'U' {
				count += 1;
			}
			else {
				break;
			}
		}
		
		writeln!(writer, "{}", count).unwrap();
	}
}
use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

    let N = input.trim().parse::<i64>().unwrap();
	
	let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
	
	let mut maximum = 0;
	let mut minimum = i64::MAX;
	
	let mut total = 0;
	
	for _ in 0..N {
		let a = input.next().unwrap();
		
		total += a;
		
		if maximum < a {
			maximum = a;
		}
		if minimum > a {
			minimum = a;
		}
	}
	
	writeln!(writer, "{}", total - maximum - minimum).unwrap();
}
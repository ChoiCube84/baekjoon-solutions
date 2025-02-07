use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let T = input.trim().parse::<i64>().unwrap();
	
	for _ in 0..T {
    	let mut input = String::new();
        stdin().read_line(&mut input).unwrap();
        
		let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

		let N = input.next().unwrap();
		let A = input.next().unwrap();
		let D = input.next().unwrap();
		
		writeln!(writer, "{}", ((N-1) * N / 2) * D + N * A).unwrap();
	}
}
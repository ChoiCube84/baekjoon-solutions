use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let T = input.trim().parse::<i128>().unwrap();
	
	for _ in 0..T {
		let mut input = String::new();
    	stdin().read_line(&mut input).unwrap();
		
		let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i128>);

		let N = input.next().unwrap();
		let M = input.next().unwrap();
		
		let mut fact : [i128; 31] = [0; 31];
		
		fact[0] = 1;
		
		for i in 1..M+1 {
		    fact[i as usize] = i * fact[(i-1) as usize];
		}
		
		let result = fact[M as usize] / (fact[N as usize] * fact[(M - N) as usize]);
		
		writeln!(writer, "{}", result).unwrap();
	}
}
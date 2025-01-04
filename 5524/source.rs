use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let N = input.trim().parse::<usize>().unwrap();
	
	for _ in 0..N {
	    let mut input = String::new();
		stdin().read_line(&mut input).unwrap();
		write!(writer, "{}", input.to_lowercase()).unwrap();
	}
}
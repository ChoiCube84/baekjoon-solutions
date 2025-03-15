use std::io::{stdin, stdout, BufWriter, Write};
use std::mem::swap;

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

    let mut N = input.next().unwrap();
    let mut M = input.next().unwrap();

    if N > M {
        swap(&mut N, &mut M);
    }

    writeln!(writer, "{}", N-1 + N * (M-1)).unwrap();
}
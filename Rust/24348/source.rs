use std::io::{stdin, stdout, BufWriter, Write};
use std::cmp::max;

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let a = input.next().unwrap();
    let b = input.next().unwrap();
    let c = input.next().unwrap();

    writeln!(writer, "{}", max(max(a * b + c, a * c + b), b * c + a)).unwrap();
}

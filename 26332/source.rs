use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

    let n = input.trim().parse::<i64>().unwrap();

    for _ in 0..n {
        let mut input = String::new();
        stdin().read_line(&mut input).unwrap();

        let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

        let c = input.next().unwrap();
        let p = input.next().unwrap();

        writeln!(writer, "{} {}", c, p).unwrap();
        writeln!(writer, "{}", c * (p - 2) + 2).unwrap();
    }
}
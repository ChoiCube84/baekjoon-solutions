use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let k = input.next().unwrap();
    let n = input.next().unwrap();

    if n <= 1 {
        writeln!(writer, "-1").unwrap();    
    }
    else if (k * n) % (n-1) == 0 {
        writeln!(writer, "{}", (k * n) / (n-1)).unwrap();
    }
    else {
        writeln!(writer, "{}", (k * n) / (n-1) + 1).unwrap();
    }
}

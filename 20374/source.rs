use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut euro = 0;
    let mut cent = 0;

    let mut input = String::new();
    while stdin().read_line(&mut input).is_ok() {
        let Ok(money) = input.trim().parse::<String>() else {
            break;
        };

        let mut nums = money.split(".").flat_map(str::parse::<u64>);

        let Ok(e) = nums.next().ok_or("") else {
            break;
        };

        let Ok(c) = nums.next().ok_or("") else {
            break;
        };

        euro += e;
        cent += c;

        input.clear();
    }

    euro += cent / 100;
    cent %= 100;

    writeln!(writer, "{}.{:02}", euro, cent).unwrap();
}

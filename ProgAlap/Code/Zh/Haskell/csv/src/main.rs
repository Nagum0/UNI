#![allow(unused)]

fn get_csv_columns(csv: Vec<Vec<&str>>) -> Vec<Vec<&str>> {
    let num_rows = csv.len();
    let num_cols = csv[0].len();

    (0..num_cols)
        .map(|col_index| {
            (0..num_rows)
                .map(|row_index| csv[row_index][col_index])
                .collect()
        })
        .collect()  
}

fn get_csv_columns2(csv: Vec<Vec<&str>>) -> Vec<Vec<&str>> {
    let mut result: Vec<Vec<&str>> = Vec::new();

    for col_index in 0..csv[0].len() {
        result.push(Vec::new());
        for row_index in 0..csv.len() {
            result[col_index].push(csv[row_index][col_index]);
        }
    }

    result
}

fn main() {
    let csv: Vec<Vec<&str>> = vec![
        vec!["Bene Zeki", "19", "Male", "Coding"],
        vec!["Felix Argyle", "21", "Male", "Healing"],
        vec!["Bunti", "2", "Female", "Sleeping"]
    ];
    println!("{:?}", csv);
    let result = get_csv_columns2(csv);
    println!("{:?}", result);
}
use std::collections::HashMap;

pub fn lzw_compression(input: &String) -> Vec<usize> {
    let mut output: Vec<usize> = Vec::new();
    let mut dict: HashMap<String, usize> = HashMap::from([
        (String::from("A"), 1),
        (String::from("B"), 2),
        (String::from("C"), 3),
    ]);
    let mut dict_count: usize = 3;

    let mut i = 0;
    let input_chars = input.chars().collect::<Vec<char>>();
    while i < input_chars.len() {
        let mut current_string = String::from(input_chars[i]);

        while i + 1 < input_chars.len()
            && dict.contains_key(format!("{}{}", current_string, input_chars[i + 1]).as_str())
        {
            current_string.push(input_chars[i + 1]);
            i += 1;
        }

        output.push(dict[current_string.as_str()]);

        if i + 1 < input_chars.len() {
            dict_count += 1;
            dict.insert(
                format!("{}{}", current_string, input_chars[i + 1]),
                dict_count,
            );
        }

        i += 1;
    }

    output
}

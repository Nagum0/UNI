fn apply_func<F>(vec: &mut Vec<i32>, f: F) where F: Fn(i32) -> i32 {
    *vec = vec.iter_mut()
       .map(|x: &mut i32| f(*x))
       .collect();
}

fn main() {
    let f = |x: i32, y: i32| x * y;
    println!("{}", f(5, 5));
    let mut vec: Vec<i32> = vec![1,2,3,4,5];
    println!("{:?}", vec);
    apply_func(&mut vec, |x| x + 1);
    println!("{:?}", vec);

    let sum: i32 = vec.iter()
                      .fold(0, |acc, x| acc + x);
    println!("{}", sum);

    let new_vec: Vec<i32> = vec.iter()
                               .fold(Vec::new(), |mut acc, x| {
                                    acc.push(*x * 2);
                                    acc
                               });
    println!("{:?}", new_vec);
}

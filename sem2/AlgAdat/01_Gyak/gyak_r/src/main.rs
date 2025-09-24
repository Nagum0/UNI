#![allow(unused)]

/// AlgAdat gyakorlat 1
/// 12/02/2024
/// Linearis kereses;
/// Logaritmikus kereses;
/// Maximumkivalasztasos rendezes;

// Time complexity: O(n)
fn lin_ker(t: &[i32], b: i32) -> Option<usize> {
    for (i, v) in t.iter().enumerate() {
        if *v == b {
            return Some(i);
        }
    }

    None
}

// Time complexity: O(logn)
fn log_ker(t: &[i32], b: i32) -> Option<usize> {
    let mut ah: usize = 0;
    let mut fh: usize = t.len() - 1;
    
    while ah <= fh {
        let koz: usize = ah + (fh - ah) / 2;
        
        if t[koz] == b {
            return Some(koz);
        }
        else if t[koz] < b {
            ah = koz + 1;
        }
        else {
            fh = koz - 1;
        }
    }

    None
}

// Time complexity: O(n^2)
fn max_val_rend(t: &mut [i32]) {
    println!("{:?}", t);

    let mut max_ind: usize = 0;
    let mut n: usize = t.len();

    for i in 0..n {
        max_ind = i;
        println!("{:?}", t);

        for j in i + 1..n  {
            if t[j] > t[max_ind] {
                max_ind = j;
            }
        }

        if max_ind != i {
            t.swap(i, max_ind);
            println!("{}", max_ind);
        }
    }
}

fn main() {
    // lin_ker:
    let xs: Vec<i32> = vec![1,2,53,7];
    println!("lin_ker result: {:?}", lin_ker(&xs, 53));

    // log_ker:
    let ys: Vec<i32> = vec![2,5,7,9,34,56,78];
    println!("log_ker result: {:?}", log_ker(&ys, 78));

    // max_val_rend:
    let mut zs: Vec<i32> = vec![5,6,3,4,8,11,2];
    max_val_rend(&mut zs);
    println!("max_val_rend result: {:?}", zs);
}

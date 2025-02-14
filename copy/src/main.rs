use std::env;
use std::fs::File;
use std::io::{self, copy};

fn main() -> io::Result<()> {
    let args: Vec<String> = env::args().collect();
    if args.len() < 3 {
        eprintln!("Usage: copy source destination");
        return Ok(());
    }

    let src = &args[args.len() - 2];
    let dest = &args[args.len() - 1];

    copy_file(src, dest)?;

    Ok(())
}

fn copy_file(src: &str, dst: &str) -> io::Result<()> {
    let mut src_file = File::open(src)?;
    let mut dst_file = File::create(dst)?;
    copy(&mut src_file, &mut dst_file)?;
    Ok(())
}
# csv_report.py
# Reads a CSV with a numeric column, computes simple stats per column, and writes a summary.
# Usage: python csv_report.py input.csv summary.txt
import sys
import csv
from collections import defaultdict

def main():
    if len(sys.argv) < 3:
        print("Usage: python csv_report.py <input.csv> <summary.txt>")
        sys.exit(1)

    in_path, out_path = sys.argv[1], sys.argv[2]
    rows = []
    with open(in_path, newline="", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        headers = reader.fieldnames or []
        for r in reader:
            rows.append(r)

    # Compute per-column stats for numeric-looking columns
    stats = {}
    for h in headers:
        nums = []
        for r in rows:
            val = r.get(h, "").strip()
            if val == "":
                continue
            try:
                nums.append(float(val))
            except ValueError:
                pass
        if nums:
            stats[h] = {
                "count": len(nums),
                "min": min(nums),
                "max": max(nums),
                "avg": sum(nums)/len(nums)
            }

    with open(out_path, "w", encoding="utf-8") as out:
        out.write(f"Summary for {in_path}\n")
        out.write("="*40 + "\n")
        out.write(f"Rows: {len(rows)}\n")
        out.write(f"Columns: {', '.join(headers)}\n\n")
        if not stats:
            out.write("No numeric columns detected.\n")
        else:
            for h, s in stats.items():
                out.write(f"[{h}]\n")
                out.write(f"  count: {s['count']}\n")
                out.write(f"  min:   {s['min']:.3f}\n")
                out.write(f"  max:   {s['max']:.3f}\n")
                out.write(f"  avg:   {s['avg']:.3f}\n\n")
    print(f"Summary written to {out_path}")

if __name__ == "__main__":
    main()

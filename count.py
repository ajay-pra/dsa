import os
import re

max_number = 0

def scan_directory(dir_path):
    global max_number

    for item in os.listdir(dir_path):
        full_path = os.path.join(dir_path, item)

        if os.path.isdir(full_path):
            scan_directory(full_path)
        else:
            # Only consider .cpp files (optional but recommended)
            if item.endswith(".cpp"):
                match = re.match(r'^(\d+)[-_]', item)
                if match:
                    num = int(match.group(1))
                    max_number = max(max_number, num)


# ✅ Root = current folder (DSA)
root_dir = os.path.dirname(os.path.abspath(__file__))

scan_directory(root_dir)

print("Max question number:", max_number)
print("Next question number should be:", max_number + 1)
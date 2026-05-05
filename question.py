import os
import re
from openpyxl import Workbook

# Create Excel workbook
wb = Workbook()
ws = wb.active
ws.title = "DSA Questions"

# Header row
ws.append(["Question No", "File Name", "Folder Name", "Link"])

def scan_directory(dir_path):
    for item in os.listdir(dir_path):
        full_path = os.path.join(dir_path, item)

        if os.path.isdir(full_path):
            scan_directory(full_path)
        else:
            if item.endswith(".cpp"):
                # Extract question number
                match = re.match(r'^(\d+)[-_]', item)
                if match:
                    q_no = int(match.group(1))
                else:
                    q_no = ""

                # Get folder name (parent directory)
                # folder_name = os.path.basename(os.path.dirname(full_path))
                folder_name = os.path.relpath(os.path.dirname(full_path), root_dir)
                
                # Read first line safely
                try:
                    with open(full_path, 'r', encoding='utf-8') as f:
                        first_line = f.readline().strip()
                except:
                    first_line = ""

                # Clean link (remove // if present)
                if first_line.startswith("//"):
                    first_line = first_line[2:].strip()

                # Add row to Excel
                ws.append([q_no, item, folder_name, first_line])


# Root directory = current file location
root_dir = os.path.dirname(os.path.abspath(__file__))

scan_directory(root_dir)

# Save Excel file
output_file = os.path.join(root_dir, "DSA_Questions.xlsx")
wb.save(output_file)

print("✅ Excel file created at:", output_file)
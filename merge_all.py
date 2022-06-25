import os
import re
import subprocess

# https://stackoverflow.com/a/40039556
def sort_human(l):
    convert = lambda text: float(text) if text.isdigit() else text
    alphanum = lambda key: [convert(c) for c in re.split('([-+]?[0-9]*\.?[0-9]*)', key)]
    l.sort(key=alphanum)
    return l

'''
note:
this is propably the worst, least secure/flexible
code I've ever written

that said i do not care beacuse it works just fine

requires pdfunite
https://github.com/mtgrosser/pdfunite
'''

index = 0

print("[info] Started merging of the PDF files")
print(80*'-')

# chdir to src folder
os.chdir('pdf')

filenames = next(os.walk('.'), (None, None, []))[2]  # [] if no file

sort_human(filenames)

merge_command = "pdfunite"

for filename in filenames:
    print(f"[info] Adding {filename} to the merge command")
    merge_command += " " + filename
    
    index = index + 1

merge_command += " ../out.pdf"

print(f"[info] Merge command: \n{merge_command}")

os.system(merge_command)

print(f"[info] Merged {index} files")

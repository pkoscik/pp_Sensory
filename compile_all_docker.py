import os
import subprocess
import time

'''
note:
this is propably the worst, least secure/flexible
code I've ever written

that said i do not care beacuse it works just fine

requires texlive docker image:
https://hub.docker.com/r/texlive/texlive
'''

print("[info] Started bash compilation of .tex files")
print(80*'-')

start = time.time()
index = 0

# chdir to src folder
os.chdir('src')

# get all folders in root filestructure
folders = next(os.walk('.'))[1]

# initialize vars
tex_command = ""
pdf_filename = ""

for folder in folders:
    
    print(f"[info] Finding .tex file in: {folder}")

    # change directory to a selected (current) folder
    os.chdir(f'./{folder}')
    
    # find .TeX file
    try:
        tex_filename = subprocess.check_output("ls | grep *.tex", shell=True).decode("utf-8").strip()
    except Exception as e:
        print(f"[error] No .tex file found in {folder}")
        break

    # compile found .TeX file
    print(f"[info] Compling: {tex_filename}")
    tex_command = f'sudo docker run -i --rm --name latex -v \"$PWD\":/usr/src/app -w /usr/src/app registry.gitlab.com/islandoftex/images/texlive:latest latexmk -f --quiet -interaction=nonstopmode -pdf 1>/dev/null 2>/dev/null'
    os.system(tex_command)

    # find .PDF file (if not found throw an exception or smth idk)
    pdf_filename = subprocess.check_output("ls | grep *.pdf", shell=True).decode("utf-8").strip()
    print(f"[info] Created PDF file: {pdf_filename}")

    # move created PDF to pdf directory
    copy_command = os.system(f"mv -f {pdf_filename} ../../pdf/{folder}.pdf")

    # return to scr directory and clear variables for good measure
    os.chdir("..")
    tex_command = ""
    pdf_filename = ""

    print(80*'-')
    index = index+1

end = time.time()

print(f"[info] Finished! Compiled {index} files in {round(end-start)} seconds")

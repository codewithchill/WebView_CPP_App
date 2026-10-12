#ifndef INDEX
#define INDEX "<!DOCTYPE html><html lang=\"en\"><meta charset=\"UTF-8\"><meta content=\"width=device-width,initial-scale=1\"name=\"viewport\"><title>Title</title><style>body{background:#f0f0af}</style><h1>Hello!</h1><p id=\"file\"></p><script>async function main(){const file_contxt=document.querySelector(\"#file\");if(window.readFile){const file_contents=await window.readFile(\"./src/main.cpp\");file_contxt.textContent=file_contents}else{file_contxt.textContent=\"Error\"}}window.addEventListener(\"DOMContentLoaded\",main);</script></html>"
#endif

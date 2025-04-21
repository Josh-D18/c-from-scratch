# Markdown To HTML Converter

## Description:
This project is a simple yet effective Markdown to HTML converter written in C. It reads a .md file, parses key Markdown syntax (like headings, paragraphs, lists, and bold/italic text), and outputs valid HTML. The main challenge was handling nested or mixed formatting in a memory-safe and efficient way using pure C string manipulation, without relying on external libraries.

## Features:

- Converts Markdown headings (#, ##, etc.) to corresponding HTML <h1>, <h2>, etc.
- Handles paragraphs, line breaks, and basic formatting like **bold** and _italic_
- Parses unordered lists (- or *) and wraps them in <ul> and <li> tags
- Gracefully handles edge cases like empty lines, inconsistent spacing, and malformed input

## Setup:
To run the project:
1. git clone https://github.com/yourusername/nday-c-projects.git
2. cd markdown-to-html
3. make
4. ./md2html input.md > output.html (you can switch to use your own file names)

## Challenges:
- A summary of problems faced and how they were solved.

## Learnings:
- Highlight new skills learned and any optimizations made during development.

## Screenshots/Diagrams:
- Add relevant screenshots or architecture diagrams.

## License:
MIT

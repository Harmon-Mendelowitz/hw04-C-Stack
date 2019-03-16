.PHONY: assignment

assignment: hw04.pdf

hw04.pdf: hw04.md
	pandoc --from markdown --standalone --out hw04.pdf hw04.md

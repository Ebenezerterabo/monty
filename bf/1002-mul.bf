,>,>,>++++++   ; Read three inputs and increment the value at the current memory cell by 6.

[
	>++++++++  ; Loop: Increment the value at the current memory cell by 8.
	<-
]

>>++++++       ; Move two cells to the right and increment the value at the next cell by 6.

[
	>++++++++  ; Loop: Increment the value at the next memory cell by 8.
	<-
]

>              ; Move one cell to the right.

[
	-          ; Loop: Decrement the value at the current memory cell until it reaches zero.
	<<<<-      ; Move four cells to the left.
	<-
	>>>>>      ; Move five cells to the right.
]

<<<<<          ; Move five cells to the left.

[
	>           ; Move one cell to the right.
	[
		>+      ; Increment the value at the current memory cell by 1.
		>>+     ; Move two cells to the right and increment the value at the next cell by 2.
		<<<-    ; Move three cells to the left and decrement the value at the current memory cell by 1.
	]
	>>>         ; Move three cells to the right.
	[
		-       ; Decrement the value at the next memory cell by 1.
		<<<+    ; Move three cells to the left and increment the value at the current memory cell by 1.
		>>>
	]
	<<<<-       ; Move four cells to the left.
]

>>             ; Move two cells to the right.

[
	-           ; Loop: Decrement the value at the current memory cell by 1.
	>+          ; Move one cell to the right and increment the value at the current memory cell by 1.
	<           ; Move one cell to the left.
]

>.             ; Output the value at the current memory cell as a character.

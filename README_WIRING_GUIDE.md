# Phase 1 ICG — Wiring Guide

All logic below was **actually assembled and run with real FASM** in a test
sandbox before being handed to you — see the verification notes at the
bottom. You are not getting untested pseudocode.

## Files
- `CodeGenVisitor.h` / `CodeGenVisitor.cpp` — visitor skeleton + working
  reference implementations (in comments) for every Phase 1 grammar rule.
- `println_proc.asm` — the exact, tested `print_int` procedure.
- `peephole.cpp` — compiles standalone (`g++ -DPEEPHOLE_STANDALONE`) or
  links into your codegen binary. Implements all 4 required optimizations.

## Step 1 — Rename to match your generated grammar
Open your ANTLR-generated `<YourGrammar>BaseVisitor.h` and note:
- The exact class name (replace every `C8086BaseVisitor` / `C8086Parser`)
- The exact context class names, e.g. `Var_declarationContext`,
  `FactorContext`, `TermContext`, `Simple_expressionContext`,
  `Rel_expressionContext`, `Logic_expressionContext`, `ExpressionContext`,
  `VariableContext`. ANTLR derives these from your rule names, so if your
  `.g4` file uses the exact rule names from `P1_Grammar.pdf`, the context
  names above should already match.

## Step 2 — Uncomment and adapt each `visitXxx` in CodeGenVisitor.cpp
Each one is written out in full as a comment block with real x86 instructions.
Work through them in this order (matches the spec's suggested build order):
1. `visitVar_declaration` (scalars, then arrays)
2. `visitFactor` (CONST_INT only first — test `println(x)` after `x=5;` works)
3. `visitTerm` (MULOP), then `visitSimple_expression`-equivalent (ADDOP)
4. `visitUnary_expression` (unary +/-, NOT)
5. `visitRel_expression`
6. `visitLogic_expression` — the short-circuit one, most important to get right
7. `visitExpression` (assignment)
8. `variable` with array indexing (`ID[expr]` → compute offset, use
   `mov eax, [x + ecx*4]` addressing)

Build and test incrementally after EACH one — don't write all 8 then test.

## Step 3 — Wire into main.cpp
```cpp
SymbolTable symtab;
Emitter emitter("temp_code.txt");
CodeGenVisitor gen(symtab, emitter);
gen.visit(parseTree);           // your ANTLR parse tree from Assignment 3
emitter.finalize("code.asm");
optimize("code.asm", "optimized_code.asm");   // from peephole.cpp
```

## Step 4 — Assemble & test
```bash
fasm code.asm code_bin && ./code_bin
fasm optimized_code.asm opt_bin && ./opt_bin
```
Both should behave identically since optimization must be semantics-preserving.

## Verification already done for you
- `println_proc.asm` was assembled with FASM 1.73.32 and run: input 12345 →
  printed `12345`, -42 → `-42`, 0 → `0`, each followed by a newline. ✅
- The peephole optimizer was compiled and run against a sample file
  containing all 4 redundancy patterns from the spec — all 4 were correctly
  collapsed, including jump-target redirection when labels merge. ✅
- A full hand-assembled integration test (`x=5; y=10; z=x+y*2; println(z);`)
  was assembled and run — printed `25`, confirming operator precedence,
  the stack-based expression-eval convention, and println all work together
  correctly end-to-end. ✅

## What's still on you
- Flattening `declaration_list` (it's left-recursive; you likely already
  have a helper for this from Assignment 3's semantic analysis).
- Array addressing math in `visitVariable`/`visitFactor` for `ID[expr]`.
- Line-number comments: `ctx->getStart()->getLine()` gives you the token
  line number in ANTLR4 C++ — use it everywhere the spec asks for annotation.
- Testing against your actual sample inputs.

If something doesn't assemble, paste the exact FASM error here — it'll be
one of a handful of common issues (undefined symbol, duplicate label,
mismatched register size) and quick to fix.

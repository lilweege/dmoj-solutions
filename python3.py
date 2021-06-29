
# def foo():
# 	x = 5
# 	y = x + 1
# 	def magic(n):
# 		n += 1
# 	magic(y)

def new_magic(n):
	print(n)


code = foo.__code__
code_t = type(code)

new_consts = tuple(
	new_magic.__code__ if type(const) == code_t else const
	for const in code.co_consts
)

new_code = code_t(
	code.co_argcount,
	code.co_posonlyargcount,
	code.co_kwonlyargcount,
	code.co_nlocals,
	code.co_stacksize,
	code.co_flags,
	code.co_code,
	new_consts,
	code.co_names,
	code.co_varnames,
	code.co_filename,
	code.co_name,
	code.co_firstlineno,
	code.co_lnotab,
	code.co_freevars,
	code.co_cellvars
)


func_t = type(foo)
new_foo = func_t(new_code, foo.__globals__)
new_foo()
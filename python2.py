# def outer():
# 	secret = []
# 	def inner():
# 		secret.append(1)
# 	return inner

# x = outer()
# del outer

print(x.__closure__[0].cell_contents)
# class Magic(object):
# 	def method(self):
# 		print 'Success' if self is None else 'Fail'

Magic.method.__func__(None)
# Magic.method.__call__(None) in py3
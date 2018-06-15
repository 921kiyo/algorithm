class Singleton:
    def __init__(self, decorated):
        print("decorated ", decorated)
        self._decorated = decorated

    def instance(self):
        try:
            return self._instance
        except AttributeError:
            self._instance = self._decorated()
            print("self._decorated()", self._decorated())
            return self._instance
    def __call__(self):
        return TypeError("Singletons must be accessed through 'instance()'.")

    def __instancecheck__(self, inst):
        print("instancecheck")
        return isinstance(inst, self._decorated)


@Singleton
class Foo:
    def __init__(self):
        print("foo created")


f = Foo()
f = Foo.instance()
g = Foo.instance()

print(f == g)

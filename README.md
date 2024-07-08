# Kat's NeetCode Tracker
Greetings stranger! Just practicing during my seasonal job

---
## Lessons learned
---
### Python

Arrays and Hashing
- `defaultDict` (prevent key errs; e.g. via defaultdict(int) --> it will auto generate a val of 0 if the key misses)
- `frozenSet`: immutable set, hash safe for dict keys
- Apply key on `sort()`: by using the `key=` parameter you can specify a function/callable to be called on each list element *prior* to making comparisons
	- e.g. `sorted_items = sorted(counter.items(), key=lambda item: item[1], reverse=True)`
- Provide default arguments to `.get` e.g. `count.get(n,0)`
- join syntax: `''.join(f'..' for string in strs)`

### C++

Arrays and Hashing
- Can directly index into vectors using chars (translated into ASCII e.g. count [c-'a'] where c ranges from 'a' to 'z'
- `unordered_map<...>` vs `map<...>` 
- `s.substr(pos, len)`
- Use prefix and postfix approach for product except self method
- Use `stoi()` for string to int conversion e.g. int len = stoi(s.substr(i, j-i)
- Use `isalnum` to check if char (returns true if its a digit OR punctuation! If we want to ignore spaces this function is necessary)
- `tolower()` for string lower case

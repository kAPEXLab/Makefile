---
layout: default
title: example5
parent: Examples
nav_order: 5
---


# example5

## Files in `example5/`
{% include listdir.html dir:'/example5/' exclude_ext:"o|d" %}

---

### Project layout
- `include/` — headers
- `src/` — sources
- `build/` — generated objects and dependency files

## README (example-level)
{% capture md %}{% include_relative example5/readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative example5/Makefile %}
```

### include/add.h
```c
{% include_relative example5/include/add.h %}
```

### include/hello.h
```c
{% include_relative example5/include/hello.h %}
```

### src/add.c
```c
{% include_relative example5/src/add.c %}
```

### src/hello.c
```c
{% include_relative example5/src/hello.c %}
```

### src/main.c
```c
{% include_relative example5/src/main.c %}
```


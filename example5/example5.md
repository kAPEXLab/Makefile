---
layout: default
title: Example5 Scalable C Project with Directory-Structured Makefile
nav_order: 5
---


# Example5 Scalable C Project with Directory-Structured Makefile

## Files in `example5/`
{% include listdir.html dir='/example5/' exclude_ext="o|d" %}

---

### Project layout
- `include/` — headers
- `src/` — sources
- `build/` — generated objects and dependency files

## README (example-level)
{% capture md %}{% include_relative readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative Makefile %}
```

### include/add.h
```c
{% include_relative include/add.h %}
```

### include/hello.h
```c
{% include_relative include/hello.h %}
```

### src/add.c
```c
{% include_relative src/add.c %}
```

### src/hello.c
```c
{% include_relative src/hello.c %}
```

### src/main.c
```c
{% include_relative src/main.c %}
```


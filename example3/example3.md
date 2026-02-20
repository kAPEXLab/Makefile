---
layout: default
title: example3
parent: Examples
nav_order: 3
---


# example3

## Files in `example3/`
{% include listdir.html dir='/example3/' %}

---

## README (example-level)
{% capture md %}{% include_relative readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative Makefile %}
```

## hello.h
```c
{% include_relative hello.h %}
```

## hello.c
```c
{% include_relative hello.c %}
```

## main.c
```c
{% include_relative main.c %}
```


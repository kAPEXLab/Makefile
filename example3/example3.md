---
layout: default
title: Example3 Advanced Makefile for Building myapp
nav_order: 3
---


# Example3 Advanced Makefile for Building myapp

## Files in `example3/`
{% include listdir.html dir='/example3/' %}

---

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


---
layout: default
title: example2
parent: Examples
nav_order: 2
---


# example2

## Files in `example2/`
{% include listdir.html dir='/example2/' %}

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


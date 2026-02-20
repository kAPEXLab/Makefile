---
layout: default
title: example2
parent: Examples
nav_order: 2
---


# example2

## Files in `example2/`
{% include listdir.html dir:'/example2/' %}

---

## README (example-level)
{% capture md %}{% include_relative example2/readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative example2/Makefile %}
```

## hello.h
```c
{% include_relative example2/hello.h %}
```

## hello.c
```c
{% include_relative example2/hello.c %}
```

## main.c
```c
{% include_relative example2/main.c %}
```


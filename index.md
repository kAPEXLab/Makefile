---
title: Home
layout: default
nav_order: 1
---

{% comment %}
Render the repository's root readme.md AS the first visible page.
{% endcomment %}

{% capture md %}{% include_relative readme.md %}{% endcapture %}
{{ md | markdownify }}

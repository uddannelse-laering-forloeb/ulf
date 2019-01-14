# ULF Workflow
## ULF project relation
- Required module

## Description
The workflow module is a key part of the ULF setup. It's main purpose is to
support an editorial workflow, where course providers create content and have it
reviewed by an editor before it is published. Editors and course providers are
notified by mail when changes are made to content. The workflow process is built
on top of several contrib modules, mainly contrib/workbench_moderation, contrib/mail_edit and contrib/scheduler.
- Contains configuration related to the editorial workflow process.
- Defines workbench moderation states.
- Defines workbench moderation transitions.
- Defines Workbench panel pages.
- Defines workflow related views e.g views used by workbench.
- Defines cron jobs related unpublishing and clearing trashed content.
- Defines several submit handlers related to publishing, unpublishing, reviewing, and trashing content.
- Defines mail types related to workflow.
- Heavily modifies the node forms that have workflow enabled:
  - course
  - course_educators
  - course_provider_news

---
title: 'Introducing the Slackbot Router: Bringing HOT tools right in our Slack channel'
date: 2020-09-04 13:00:00 Z
Summary Text: As part of the 2020 Outreachy summer program, we developed a Slackbot
  Router project that utilises slash commands to deliver information on different
  HOT tools to the user. This allows the community to more efficiently access and
  share data between members and increase productivity.
Person:
- Andria Hibe
---

## Planning the Slackbot Router

Slackbot Router is a greenfield project, so we had the opportunity to carefully plan its architecture before starting.

Mainly, we had to plan the project around four (4) considerations:

### Maintainability | Scalability  | Cost Efficiency | Ease of Contribution

The Slackbot Router must be maintainable and adding new features as well as modifying existing features—whether it’s to fix bugs or to extend functionality—must be as straightforward as possible with the least amount of intervention to other features and parts of the architecture.

This means that features must be independent from each other and the core of the architecture which handles how the app functions—the router—must be able to handle new features and changes without needing to be modified every time.

The project must also be scalable both ways—up to infinity and down to zero—without a significant increase in labour and resources. The app should be as performant with 10,000 people using it as it would with only one user, and the changes needed to accommodate this change in number of users should be minimal. This includes keeping costs associated with building and running the Slackbot Router as low as possible.

And importantly, contributors must find it easy to improve, maintain, and add to existing features to ensure that the project continues to grow.

![slack-router](https://user-images.githubusercontent.com/12103383/84057200-f6620000-a9d4-11ea-9b74-fd4ecd9eb27b.png)

To make sure we achieved these goals the app is designed so that new features and changes to existing ones will not have any effects on any other part of the app. Code readability, robust documentation, and minimal use of libraries were also a focus so future contributors will be able to jump in the code base and pick up tickets readily and maintainers will spend less time guiding contributors and updating dependencies.

We are also utilising AWS microservices to ensure the application is scalable and to keep costs down. The application is event-based—meaning it only needs to run at the time it is triggered—and lightweight in its use of resources; a serverless architecture is then ideal as it allows us to pay only for the resources that are being used and lowers overhead costs in maintaining the application.

For a full explanation of how the application handles and routes events, [visit our docs](https://github.com/hotosm/slack-bots/blob/master/docs/architecture.md).

## How to use the Slackbot Router

To use the Slackbot Router slash commands, write */name-of-command* in the message field of any Slack channel or direct message. Some commands might require you to input in additional data such as a project ID or username. When in doubt, you can use the command */command-help* to see a list of all active slash commands and a short description of each. For some commands, you can also type */name-of-command help* to see more detailed instructions on how to use them.

The Slackbot Router currently has the following slash commands:

* _**/health-tm**_ - Checks the status of the Tasking Manager and returns its current status and other statistics.

![health-tm](https://user-images.githubusercontent.com/54427598/87404675-8f0e2000-c612-11ea-920e-cd3b7292dcca.png)


+ _**/health-leaderboard**_ - Allows users to know if the Missing Maps leaderboard is up-to-date and if not, the amount of time it is delayed.

![health-leaderboard](https://user-images.githubusercontent.com/54427598/87404630-80276d80-c612-11ea-8316-02ca8a1b5101.png)


+ _**/osmcha-stats**_ - Allows users to filter changesets based on project ID or hashtag(s) and returns stats on the changesets including the number of suspicious changesets and a list of flags.

![osmcha-stats-project](https://user-images.githubusercontent.com/54427598/87515724-5cc2f800-c6d0-11ea-9c7b-0fe29049838b.png)


+ _**/tm-stats**_ - Returns information on the Tasking Manager, projects, or users depending on parameters used.

![tm-stats-project](https://user-images.githubusercontent.com/54427598/87519968-6fd8c680-c6d6-11ea-9040-8dff25378523.png)


+ _**/command-help**_ - Returns a list, including a short description, of all Slack slash commands that users can use.

![command-help](https://user-images.githubusercontent.com/54427598/90256846-6c358c80-de9a-11ea-88e6-92f348f88b41.png)

You can see more use cases for each command in the docs.

This is only the beginning of this project! We welcome and encourage contributors to help us. Visit the repository and check out the docs for instructions on how you can contribute.

Planned improvements and features for the Slackbot Router can be found in the GitHub Issues of the repo. Request to be assigned a ticket or if you want to create a new command or feature, post a new issue!

**[Visit the GitHub repo for the Slackbot Router](https://github.com/hotosm/slack-bots)**
